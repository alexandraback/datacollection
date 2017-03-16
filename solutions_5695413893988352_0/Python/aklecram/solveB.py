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
            C, J = tuple([x for x in _file.readline().strip().split(" ")])
            arguments.append((_case + 1, (C, J)))

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

def fits(N, n):
    for i in range(len(N)):
        if N[i] != "?" and N[i] != n[i]:
            return False
    return True

def solve_small(C, J):
    n = len(C)
    fmt = "%0" + ("%s" % n) + "d"
    result = (10**30, None, None)
    for cc in range(10**n):
        for jj in range(10**n):
            c = fmt % cc
            j = fmt % jj
            if fits(C, c) and fits(J, j):
                result = min(result, (abs(cc-jj), c, j))
    return "%s %s" % (result[1], result[2])


def solve(C, J):
    print(C, J)
    return solve_small(C, J)

run()
#run(Pool(4))
