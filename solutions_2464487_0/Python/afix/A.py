from math import *
fin = open("input.txt", "r")
fout = open("output.txt", "w")
f = fin.readlines()
T = int(f[0])
for T1 in range(1, T+1):
    Q = f[T1].split()
    r = 2*int(Q[0])-1
    t = int(Q[1])
    L = 0
    R = 10.**12
    while (R - L > 0.001):
        m = (L + R)/2
        if (2*m*m+r*m <= t):
            L = m
        else:
            R = m
    print L, R
    n = int(R)
    print >> fout, "Case #" + str(T1) + ":", n
fout.close()
