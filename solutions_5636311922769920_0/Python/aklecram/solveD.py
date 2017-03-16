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
            k, c, s = tuple([int(x) for x in _file.readline().split(" ")])
            arguments.append((_case + 1, (k, c, s)))

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

def add_level(pattern, original):
    return "".join(original if p == "0" else "1" * len(original) for p in pattern)

def fractal(k, c, i):
    start = "".join("1" if i == j else "0" for j in range(k))
    pattern = start
    for j in range(c - 1):
        pattern = add_level(pattern, start)
    return pattern

def position(k, c, to_check):
    result = 0
    block = 1
    for p in to_check:
        result += block * p
        block *= k
    return result

def solve(k, c, s):
    if s * c < k:
        return 'IMPOSSIBLE'
    result = []
    i = 0
    while i < k:
        result.append(1 + position(k, c, range(i, min(i + c, k))))
        i += c
    return " ".join(str(r) for r in result)
    
run()

import random

def speed_test():
    for i in range(20):
        k = random.randint(1, 100)
        c = min(random.randint(1, 100), (10 ** 18) // k)
        s = random.randint(1, k)
        solve(k, c, s)

def test():
    for i in range(10):
        k = random.randint(1, 10)
        c = random.randint(1, 5)
        to_check = set(random.randint(0, k-1) for _ in range(c))
        p = position(k, c, to_check)
        for i in to_check:
            assert(p < k ** c)
            assert(fractal(k, c, i)[p] == "1")

speed_test()
test()
#run(Pool(4))
