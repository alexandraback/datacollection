import math
def rl():
    return fin.readline()
def r():
    return fin.read()
def w(o):
    print >>fout, o

def solve():
    T = int(rl())+1
    P = []
    a = 0
    for i in xrange(1,10000000):
        s = str(i)
        if s == s[::-1]:
            i2 = i**2
            s = str(i2)
            if s == s[::-1]:
                P.append(i2)
                a += 1
    for t in xrange(1,T):
        S = rl().split()
        A = int(S[0])
        B = int(S[1])
        a = 0
        for i in P:
            if i > B:
                break
            if i >= A:
                a+=1
        w("Case #%d: %s" % (t,a))

fin = open('test.in', 'r')
fout = open('test.out', 'w')
solve()
fin.close()
fout.close()