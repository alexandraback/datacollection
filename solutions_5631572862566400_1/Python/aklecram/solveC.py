import sys
from multiprocessing import Pool
from collections import defaultdict

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
            bffs = tuple([int(x) for x in _file.readline().split(" ")])
            arguments.append((_case + 1, (n, bffs)))

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

def max_follower_line(followers, kid, kbff):
    todo = [(kid, 0)]
    result = 0
    while True:
        if len(todo) == 0:
            return result
        k, n = todo.pop()
        result = max(result, n)
        for f in followers[k]:
            if f != kbff:
                todo.append((f, n + 1))

def reciprocal(bffs):
    result = set()
    for kid in bffs:
        if bffs[bffs[kid]] == kid:
            result.add(kid)
    return result

def cycle_length(bffs, kid):
    visited = set()
    n = 0
    curr = kid
    while True:
        if curr in visited:
            if curr == kid:
                return n
            else:
                return 0
        visited.add(curr)
        curr = bffs[curr]
        n += 1

def solve(n, bffs_list):
    followers = defaultdict(set)
    bffs = dict((i+1, bffs_list[i]) for i in range(n))
    for k, v in bffs.items():
        followers[v].add(k)
    rs = reciprocal(bffs)
    result1 = len(rs) + sum(max_follower_line(followers, r, bffs[r]) for r in rs)
    result2 = max(cycle_length(bffs, kid) for kid in bffs)
    return max(result1, result2)

run()

#assert(solve(4, [2, 3, 4, 1]) == 4)
#assert(solve(4, [3, 3, 4, 3]) == 3)
#assert(solve(8, [2, 3, 4, 1, 6, 7, 8, 5]) == 4)
#assert(solve(8, [3, 3, 4, 3, 7, 7, 8, 7]) == 6)
#
#import random
#print(solve(1000, [random.randint(1, 1000) for i in range(1000)]))
#run(Pool(4))
