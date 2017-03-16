from contextlib import contextmanager


@contextmanager
def in_out(problem, size):
    """
    gcj_context.py
    Beta work.
    Created by Robert King
    https://plus.google.com/107945104877181936322/

    "It works on my machine"

    Approximately how to get it working:

    1) install the command line tool:
    https://code.google.com/p/codejam-commandline/

    2) C:\Users\robert\code\play\codejam\codejam-commandline-1.2-beta1>python gcj_clear_contest.py

    3) Update config\user_config.py note the password is an application specific password from gmail:

    {
    'host'                : 'code.google.com',
    'user'                : 'youraccount@gmail.com',
    'data_directory'      : './source',
    'input_name_format'   : '{problem}-{input}-{id}.in',
    'output_name_format'  : '{problem}-{input}-{id}.out',
    'source_names_format' : ['{problem}-{input}-{id}.py'],
    'password'            : "qwerppjjjjiiasdf"
    }

    4) replace 1460488 with the id of whatever contest you want (found in the contest dashboard url):
     C:\Users\robert\code\play\codejam\codejam-commandline-1.2-beta1>python gcj_init_contest.py 1460488

    5) create the folder C:\Users\robert\code\play\codejam\codejam-commandline-1.2-beta1\source

    5a) make sure the "source" folder is empty of solutions from previous contests to avoid bugs.

    for the following examples I'll use B.y (although it could be A.py or C.py etc)

    6) to solve problem B, inside the source folder, create file B.py (in general for problem X make X.py)

    7) inside B.py, create your solution:

from gcj_context import in_out, test_in_out


def solve_test_case(data):
    stuff = next(data)
    return "my_answer_from_stuff"


def main():
    #with test_in_out() as (in_file, out_file):
    with in_out("B", "small") as (in_file, out_file):
        data = (line.strip() for line in in_file)
        test_cases = int(next(data))
        for case in range(1, test_cases + 1):
            answer = solve_test_case(data)
            out_file.write("Case #{}: {}\n".format(case, answer))
            print "solved {} (I hope)".format(case)


main()



    8) save gcj_context.py to the source folder .\source\gcj_context.py

    9) from the folder "codejam-commandline-1.2-beta1" (as your working directory), type "python source\B.py"
    """
    problem = problem.upper()
    size = size.lower()
    import os
    from time import sleep
    from functools import partial
    join = partial(os.path.join, "source")
    attempt = 0
    existing_attempts = set(os.listdir("source"))
    while True:
        name_solution = "{}-{}-{}.py".format(problem, size, attempt)
        name_in = "{}-{}-{}.in".format(problem, size, attempt)
        name_out = "{}-{}-{}.out".format(problem, size, attempt)
        if existing_attempts.isdisjoint(set([name_solution, name_in, name_out])):
            print "using " + " & ".join([name_solution, name_in, name_out])
            break
        attempt += 1

    with open(join("gcj_context.py")) as gcj_context_file:
        code = gcj_context_file.read()
    with open(join(problem+".py")) as code_file:
        code += code_file.read()
    with open(join(name_solution), 'w') as submitted_code:
        submitted_code.write(code)

    os.system("python gcj_download_input.py {} {} {}".format(problem, size, attempt))
    with open(join(name_in)) as in_file, open(join(name_out), 'w') as out_file:
        yield in_file, out_file
    os.system("python gcj_submit_solution.py {} {} {}".format(problem, size, attempt))
    sleep(3)
    print "getting status.."
    os.system("python gcj_get_status.py")

@contextmanager
def test_in_out(name_in="in.txt", name_out="out.txt"):
    import os
    from functools import partial
    join = partial(os.path.join, "source")
    print "Running Test from {} to {}".format(name_in, name_out)
    with open(join(name_in)) as in_file, open(join(name_out), 'w') as out_file:
        yield in_file, out_file
    print "test complete, check {}".format(name_out)
    #feel free to add a diff tool to compare between out.txt and sample_out.txtfrom gcj_context import in_out, test_in_out
from random import shuffle
#
# cache = {}
# parent = {}
#
# def solve(X, Y, d, path):
#     #print X, Y, d
#     if len(path) > 10:
#         return None
#     if X == 0 and Y == 0:
#         return 1
#     ans = cache.get((X, Y, d), None)
#     if ans:
#         return ans
#     directions = [(0, d), (0, -d), (d, 0), (-d, 0)]
#     shuffle(directions)
#     #print directions
#     new_d = d + 1
#     #ans = min(solve(X - dx*d, Y - dy*d, new_d) for dx, dy in directions) + 1
#     answers = []
#     for dx, dy in directions:
#         answers.append(solve(X, Y, d, []))
#
#     min_length =
#     cache[(X, Y, d)] = ans
#     return ans


import pulp

def get_lp_problem(X, Y, SIZE):
    prob = pulp.LpProblem("gcj", pulp.LpMaximize)
    north = []
    south = []
    west = []
    east = []
    directions = [north, south, east, west]
    for i in range(SIZE):
        #north
        var = pulp.LpVariable('{i}_{j}'.format(i=i, j=0),
            lowBound=0, upBound=1,
            cat=pulp.LpInteger)
        directions[0].append(var)
        var = pulp.LpVariable('{i}_{j}'.format(i=i, j=1),
            lowBound=-1, upBound=0,
            cat=pulp.LpInteger)
        directions[1].append(var)
        var = pulp.LpVariable('{i}_{j}'.format(i=i, j=2),
            lowBound=0, upBound=1,
            cat=pulp.LpInteger)
        directions[2].append(var)
        var = pulp.LpVariable('{i}_{j}'.format(i=i, j=3),
            lowBound=-1, upBound=0,
            cat=pulp.LpInteger)
        directions[3].append(var)
    for i in range(SIZE):
        a, b, c, d = [directions[j][i] for j in range(4)]
        prob += sum([a, -b, c, -d]) == 1

    height = []
    width = []
    for i in range(SIZE):
        height.append((i + 1)*directions[0][i])
        height.append((i + 1)*directions[1][i])
        width.append((i + 1)*directions[2][i])
        width.append((i + 1)*directions[3][i])
    prob += sum(width) == X
    prob += sum(height) == Y
    return prob


def solve(X, Y):
    for SIZE in range(1,501):
        prob = get_lp_problem(X, Y, SIZE)
        #print "solving"
        prob.solve()
        if prob.status != 1:
            continue
        solution = []
        codes = "NSEW"
        for var in prob.variables():
            if var.varValue and abs(var.varValue) > 0.5:
                i, j = map(int, var.name.split('_'))
                solution.append((int(i), codes[j]))
        solution.sort()
        return "".join(v[1] for v in solution)

def check(s):
    d = {"N":(0, 1), "S": (0, -1), "E": (1, 0), "W": (-1, 0)}
    x, y = 0, 0
    for i in range(len(s)):
        dx, dy = d[s[i]]
        x += dx*(i+1)
        y += dy*(i+1)
    return x, y


def main():
    #with test_in_out("B-small-attempt1.in") as (in_file, out_file):
    with in_out("B", "small") as (in_file, out_file):
        data = (line.strip() for line in in_file if line.strip())
        test_cases = int(next(data))
        for case in range(1, test_cases + 1):
            X, Y = map(int, next(data).split())
            #print "--", X, Y
            answer = solve(X, Y)
            print "Case #%s: %s" % (case, answer)
            #assert (X, Y) == check(answer)
            out_file.write("Case #%s: %s\n" % (case, answer))



main()
