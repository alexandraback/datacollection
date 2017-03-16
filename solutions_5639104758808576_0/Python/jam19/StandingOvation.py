

import sys
import os
#import numpy as np
import itertools

sample = "sample"
small = "A-small-attempt0"
large = "A-large-practice"
current = small

fin = open(current + ".in", "r")
fout = open(current + ".out", 'w')
f1out = open(current + "1.out", 'w')
f2out = open(current + "2.out", 'w')

T = int(fin.readline())

def solve(N, ss):
    f = 0
    c = 0
    for i, s in enumerate(ss):
        if c < i:
            f += i - c
            c += i - c

        c += s

    return f, c

for i in range(T):
    N, S = fin.readline().split()
    ss = []
    for j in range(int(N)+1):
        ss.append(int(S[j]))
    solution = solve(int(N), ss)
    answer = "Case #%d: %s\n" % (i+1, solution[0])
    print answer
    fout.write(answer)



fin.close()
fout.close()
f1out.close()
f2out.close()