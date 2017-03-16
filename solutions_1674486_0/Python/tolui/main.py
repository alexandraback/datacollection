'''
Created on May 6, 2012

@author: disqiu
'''
FILE_NAME = "A-small-attempt0"

def read_file(file_name):
    read = open(file_name,"r")
    return read.readlines()
    
def write_file(list_string,file_name):
    out = open(file_name,"w")
    out.writelines(list_string)
    out.close()

def parse_line(da,line,parse):
    line = line.split(" ")
    l = line[da:]
    res = []
    for i in l:
        res.append(parse(i))
    return res

def string_case(i, res):
    string = "Case #" + str(i) + ": "          
        
    if res:
        string += "Yes "
    else:
        string += "No "
    
    return string + "\n"


def path(node_f, node_to, matrix):
    reachable = []
    
    to_expand = [node_f]
    expanded = []
    while len(to_expand) != 0:
        node = to_expand.pop()
        expanded.append(node)
        line = matrix[node]
        
        for l in line:
            l= l-1
            if expanded.count(l) == 0:
                to_expand.append(l)
            reachable.append(l)
        
    if reachable.count(node_to)>1:
        return True
    else:
        return False
        
    
if __name__ == '__main__':
    lines = read_file(FILE_NAME+".in")
    write = []
    lines.pop(0)
    i=0
    case = 1
    while i < len(lines):
        parsed_line = int(lines[i])
        numberLines = parsed_line
        # resolve the problem
        
        res = False
        matrix = []
        for r in range(numberLines):
            i+=1
            nodeDip = parse_line(1, lines[i], int)
            
            matrix.append(nodeDip)
            
        for node_f in range(numberLines):
            for node_to in range(numberLines):
                if node_f != node_to:
                    if path(node_f, node_to, matrix):
                        res = True        
        # define the string
        
        write.append(string_case(case, res))
        i += 1
        case += 1
    write_file(write, FILE_NAME+".out")