#! /usr/bin/env python

import sys, math
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

T = int(fin.readline())
L = {1 : 1}

for i in xrange(T):
    N = int(fin.readline())
    ans = 0
    while N >= 10:
        j = int(math.log10(N))
        print N
        if N % 10 ** ((j+1)/2) == 0:
            N -= 1
            ans += 1
            continue
        ans += N % (10 ** ((j+1)/2)) - 1
        N   -= N % (10 ** ((j+1)/2)) - 1
        print N
        M = int(str(N)[::-1])
        if M != N:
            ans += 1
            N = M
        print N
        ans += N - 10 ** j + 1
        N = 10**j - 1
        print N
    fout.write("Case #" + str(i+1) + ": " + str(ans + N) + "\n")
