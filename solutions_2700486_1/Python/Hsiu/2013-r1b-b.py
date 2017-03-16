#! /usr/bin/python -tt 

import sys
sys.path.append('/Users/hsiu/Documents/code/python')

def choose(n, k):
    """
    A fast way to calculate binomial coefficients by Andrew Dalke (contrib).
    """
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in xrange(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

T = input()
f = open("out", "w")
for Case in range(1, T+1):
    aLine = raw_input()
    aLine = aLine.split()
    for i in range(len(aLine)):
        aLine[i] = eval(aLine[i])
    N = aLine[0]
    X = aLine[1]
    Y = aLine[2]
    if X < 0:
        X = -X
    goal = (X+Y)/2
    fall = 0
    tmp = 1
    while N >= tmp:
        tmp += 4*fall + 5
        fall += 1
    full = fall - 1
    remain = N - (2*full+1)*(full+1)
    print "Case #", Case, "goal =", goal, "\tfull =", full, "\tremain =", remain, "\tY =", Y+1
    if full >= goal:
        ans = 1
    elif full+1 < goal:
        ans = 0
    else:
        Y = Y+1
        if X == 0 or remain < Y:
            ans = 0
        elif remain >= 2*goal + Y:
            ans = 1
        else:
            deno = 2**remain
            if 2*Y < remain:
                nume = deno
                for i in range(Y):
                    nume -= choose(remain, i)
                ans = float(nume)/deno
            else:
                nume = 0
                for i in range(remain-Y+1):
                    nume += choose(remain, i)
                ans = float(nume)/deno

    f.write("Case #%d: %lf\n" % (Case, ans))
