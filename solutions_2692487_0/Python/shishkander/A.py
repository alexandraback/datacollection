def cnt(A, m):
    a = A - 1
    r = 0
    while a < m:
        r += 1
        a *= 2
    #print A, m, "=>", a+1, r
    return r, a + 1

def CASE(IN):
    def rstr(): return IN.readline().strip()
    def rint(): return int(rstr())
    def rints(): return map(int, rstr().split())
    A, N = rints()
    M = sorted(rints())
    if A == 1:
        return N
    R = [0] * (N+1)
    mi = N
    for i, m in enumerate(M):
        l = N-i
        if m < A:
            R[i] = R[i-1]
        else:
            r, _A = cnt(A, m)
            assert r > 0
            #print "LR", r, l
            if r >= l:
                for j in xrange(i, N):
                    R[j] = N+1
                mi = R[i-1] + l
                #return mi
                #print "ret ", mi, R[i-1], l
                break
            else:
                R[i] = R[i-1] + r
                A = _A 
        A += m
        if R[i] + l - 1 < mi:
            mi = R[i] + l - 1
    #print R
    a = N
    for i, r in enumerate(R[:-1]):
        #print i, r, (r + N-i-1)
        a = min(a, r + N-i-1)
    #print mi, a
    assert mi >= a
    return a

def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1,t+1):
        OUT.write("Case #%i: %s\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
