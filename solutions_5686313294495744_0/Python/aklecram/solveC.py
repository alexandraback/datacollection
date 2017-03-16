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
            lines = []
            for i in range(n):
                lines.append(_file.readline()[:-1])
            arguments.append((_case + 1, (n, lines)))

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

def solve_small(n, lines):
    result = 0
    fmt = '{0:0' + ("%s" % n) + 'b}'
    for i in range(2**n):
        can_be = True
        originals = fmt.format(i)
        words1 = set()
        words2 = set()
        for j in range(n):
            if originals[j] == "1":
                w1, w2 = lines[j].split(" ")
                words1.add(w1)
                words2.add(w2)
        for j in range(n):
            if originals[j] == "0":
                w1, w2 = lines[j].split(" ")
                if w1 not in words1:
                    can_be = False
                if w2 not in words2:
                    can_be = False
        if can_be:
            result = max(result, originals.count("0"))
    return result

def solve(n, lines):
    return solve_small(n, lines)

run()
#run(Pool(4))
