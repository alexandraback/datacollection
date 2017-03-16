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
            arguments.append((_case + 1, tuple([n])))

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

def solve(n):
    if n == 0:
        return 'INSOMNIA'
    seen = set()
    i = 1
    while True:
        k = n * i
        i += 1
        seen = seen.union(int(d) for d in '%s' % k)
        if (len(seen) == 10):
            return k

run()
#run(Pool(4))
