import sys
from multiprocessing import Pool

# Add git repository with helpers to path
# The repo is publicly available at git@github.com:marcelka/cocoli.git
sys.path.append("/home/marcelka/projects/cocoli/")

def run(pool=None): # {{{
    inp=sys.argv[1]
    outp="%s.out" % inp.split(".")[0]

    with open(inp, 'r') as _file, open(outp, 'w') as out:
        _cases = int(_file.readline())
        arguments = []
        for _case in range(_cases):
            n = int(_file.readline())
            lines_rows = []
            for i in range(2 * n - 1):
                lines_rows.append(tuple([int(x) for x in _file.readline().split(" ")]))
            arguments.append((_case + 1, (n, lines_rows)))

        if pool == None:
            results = list(map(solve_wrapper, arguments))
        else:
            results = sorted(
                list(pool.imap_unordered(solve_wrapper, arguments)),
                key=lambda r: r[0])
        
        for _case, result in results:
            out.write("Case #%s: %s\n" % (_case, result))

def solve_wrapper(args):
    case_no, _args = args
    print("Solving case #%s" %(case_no))
    return (case_no, solve(*_args))
# }}}

from itertools import combinations

def check(n, rows, cols):
    cols2 = set()

    for i in range(n):
        cols2.add(tuple(rows[j][i] for j in range(n)))

    missing = cols2.difference(cols)
    if len(missing) == 1:
        return missing.pop()
        
def solve(n, lines_rows):
    for possible_rows in combinations(range(2 * n - 1), n):
        r = []
        c = []
        for i in range(2 * n - 1):
            if i in possible_rows:
                r.append(lines_rows[i])
            else:
                c.append(lines_rows[i])
        result = check(n, sorted(r), sorted(c))
        if result != None:
            return " ".join("%s" % r for r in result)
    
run()
#run(Pool(4))
