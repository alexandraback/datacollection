import sys
import numpy as np



def solve(case, Smax, S):
    print Smax, S
    x = 0
    sum = 0
    for i, s in enumerate(S):
        if sum < i:
            x += i - sum
            sum = i
        sum += s
    return x



filename_in = sys.argv[1]
filename_out = filename_in.partition('.')[0] + '.out'
with open(filename_out, "w") as fout:
    with open(filename_in, "r") as fin:
        T = int(fin.readline())
        for case in range(1, T+1):
            s = fin.readline().split()
            Smax = [int(s[0])]
            S = [int(x) for x in s[1]]
            print >> fout, "Case #%i:" % case, solve(case, Smax, S)
