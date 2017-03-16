import sys
import numpy as np



def solve(Nstr):
    N = int(Nstr)
    if N <= 20:
        return N
    digits = len(Nstr)
    result = 10
    for i in range(2, digits):
        half = i // 2
        result += 10**half - 1 # -> 10..99
        result += 1 # -> 99..01
        result += 10**(i-half) - 1 # -> 10..000
    if N == 10**(digits-1):
        return result
    if N % 10 == 0:
        result += 1
        N -= 1
    last_digits = N % (10**((digits+1)//2))
    if last_digits != 1:
        assert last_digits != 0
        N -= last_digits - 1
        result += last_digits - 1
        assert N % (10**((digits+1)//2)) == 1

    Nswapped = int(str(N)[::-1])
    if Nswapped % (10**((digits+1)//2)) > 1:
        N = Nswapped
        result += 1
    result += N % (10**(digits-1))
    return result


filename_in = sys.argv[1]
filename_out = filename_in.partition('.')[0] + '.out'
with open(filename_out, "w") as fout:
    with open(filename_in, "r") as fin:
        T = int(fin.readline())
        for case in range(1, T+1):
            Nstr = fin.readline()[:-1]
            print >> fout, "Case #%i:" % case, solve(Nstr)
