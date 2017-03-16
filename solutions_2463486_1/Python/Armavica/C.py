#! /usr/bin/python -tt

from math import sqrt

def solve(N, M):
    def is_pal(n):
        return all([a == b for (a, b) in zip(str(n), str(n)[::-1])])
    def pals(n, start=1):
        if n == 0:
            return [""]
        elif n == 1:
            return [str(m) for m in range(start,10)]
        else:
            return [str(m) + pal + str(m) for m in range(start,10) for pal in pals(n-2, 0)]
    n = int(sqrt(N))
    m = int(sqrt(M))+1
    squares = []
    for i in range(len(str(n)), len(str(m))+1):
        squares += [int(p)**2 for p in pals(i)]
    return len([1 for square in squares if square >= N and square <= M and is_pal(square)])

T = input()
for t in xrange(T):
    (N, M) = tuple((int(nb) for nb in raw_input().split(" ")))
    print "Case #"+str(t + 1)+":", solve(N, M)
