import sys
from multiprocessing import Pool

# Add git repository with helpers to path
# The repo is publicly available at git@github.com:marcelka/cocoli.git
sys.path.append("/home/marcelka/projects/cocoli/")

from primes import is_prime
from math import sqrt, ceil

def run(pool=None): # {{{
    inp=sys.argv[1]
    outp="%s.out" % inp.split(".")[0]

    with open(inp, 'r') as _file, open(outp, 'w') as out:
        _cases = int(_file.readline())
        arguments = []
        for _case in range(_cases):
            n, j = tuple([int(x) for x in _file.readline().split(" ")])
            arguments.append((_case + 1, (n, j)))

        if pool == None:
            results = list(map(solve_wrapper, arguments))
        else:
            results = sorted(
                list(pool.imap_unordered(solve_wrapper, arguments)),
                key=lambda r: r[0])
        
        for _case, result in results:
            out.write("Case #%s:%s\n" % (_case, result))

def solve_wrapper(args):
    case_no, _args = args
    print("Solving case #%s" %(case_no))
    return (case_no, solve(*_args))
# }}}

def from_base(digits, base):
    n = len(digits)
    return sum(base**i * digits[n-i-1] for i in range(n))

# Attempts to find a divisor, may abandon the search prematurely to gain speedup
def find_divisor(n):
    if not is_prime(n, 10**(-3)):
        for i in range(2, min(ceil(sqrt(n)), 10**3)):
            if n % i == 0 and i < n:
                return i
    return None

def jam_coin_data(digits):
    divs = []
    for base in range(2, 11):
        div = find_divisor(from_base(digits, base))
        if div is None:
            return None
        divs.append(div)
    return divs

def solve(n, j):
    coin = 2**(n - 1) + 1
    result = []
    while True:
        str_digits = bin(coin)[2:]
        divisors = jam_coin_data(list(int(d) for d in str_digits))
        if divisors is not None:
            result.append("\n%s %s" % (str_digits, " ".join(str(d) for d in divisors)))
            print('found', len(result))
        if len(result) == j:
            return "".join(result)
        coin += 2

def test():
    assert(from_base([9, 6, 7], 10) == 967)
    assert(from_base([1, 0, 0, 1, 0, 1], 10) == 100101)
    assert(from_base([1, 0, 0, 1, 0, 1], 2) == 37)

test()

run()
#run(Pool(4))
