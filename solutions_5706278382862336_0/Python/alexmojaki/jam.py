from fractions import gcd
from math import log2

infile = open('A-small-attempt0.in')
outfile = open('output.txt', mode='w')


def read_int_list() -> [int]:
    """
    :rtype : [int]
    """
    return list(map(int, infile.readline().split()))


def read_int() -> int:
    """
    :rtype : int
    """
    return int(infile.readline())


for c in range(read_int()):
    line = infile.readline()
    p, q = map(int, line.strip().split("/"))
    d = gcd(p, q)
    p //= d
    q //= d
    log_q = int(log2(q))
    if 2 ** log_q == q:
        ans = str(log_q - int(log2(p)))
    else:
        ans = "impossible"
    print("Case #%i: %s" % (c + 1, ans), file=outfile)

infile.close()
outfile.close()
