"""Parser Module
"""

import re

CASTING = {'int': int,
           'float': float,
           'str': str}

LINEPARSER = "<([a-zA-Z]*) ([a-zA-Z]*)>"
BLOCKSTART = "\\$([a-zA-Z]*)\\{"
ITERVAR = "%([a-zA-Z]*)"

maplist = lambda s, func: list(map(func, s.split()))

def parse(parse_string, glob = globals()):
    bindings = {"NORMAL__MAIN": 1}
    lines = list(filter(lambda x: x != "", parse_string.split("\n")))
    lines =  read_blocks(lines, 0)
    parse_block(lines, "NORMAL__MAIN", bindings, glob)
    return list(bindings["ITER__MAIN"]())[0]
    
def read_blocks(lines, start_index):
    nested = []
    index = start_index
    while index < len(lines):
        match = re.match(BLOCKSTART, lines[index])
        if match:
            block, index = read_blocks(lines, index + 1)
            initvar = "NORMAL_" + match.group(1)
            nested.append((initvar, block))
        elif lines[index] == "}":
            return nested, index
        else:
            nested.append(lines[index])
        index += 1
    return nested
    
def parse_block(lines, init_var, bindings, glob) :
    times = bindings[init_var]
    return_statement = lines[-1]
    lines = lines[:-1]
    assert type(times) == int, "Block parser must start with integer variable!"
    assert return_statement[:4] == ">>> ", \
        "Block parser must have return statement!"

    # Magic happens here
    return_statement = return_statement.replace(">>> ", "")
    return_statement = return_statement.replace("$", "NORMAL_")
    itervars = re.findall(ITERVAR, return_statement)
    for var in itervars:
        return_statement = return_statement.replace("%" + var,
                                                    "ITER_" + var + "()")

    parsed = []
    for _ in range(times):
        for line in lines:
            if type(line) == tuple: # Parse Block
                parse_block(line[1], line[0], bindings, glob)
            else:                   # Parse Line
                parse_line(line, bindings)            
        parsed.append(eval(return_statement, glob, bindings))
        
    def block_iter():
        for result in parsed:
            yield result

    iter_var = init_var.replace("NORMAL_", "ITER_")
    bindings[iter_var] = block_iter

def parse_line(format_string, bindings):
    variables = re.findall(LINEPARSER, format_string)
    try:
        read = raw_input()
    except NameError:
        read = input()
    if len(variables) == 1:
        line = [read]
    else:
        line = read.split()
    if len(line) != len(variables):
        raise ValueError("Incorrect line parser: {0} cannot parse {1}".format(
            format_string, read))
    for i in range(len(line)):
        vartype = variables[i][0]
        varname = variables[i][1]
        try:
            bindings["NORMAL_" + varname] = CASTING[vartype](line[i])
        except ValueError as e:
            raise ValueError("Cannot turn {0} into {1} for variable {2}".format(
                type(line[i]), vartype, varname))