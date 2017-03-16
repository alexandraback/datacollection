#!/usr/bin/env python

def casei(N, S, i):
    others = 0
    me = 0
    for j in xrange(i):
        others += S[i] - S[j]
    if others > 1: return 0
    print "S", S, others, me

    for j in xrange(i+1, N):
        delta = S[j] - S[i] - me
        if delta * j + me + others <= 1:
            me = S[j] - S[i]
            others += delta * (j-1)
        else:
            left = 1 - others - me
            me += left/j
            return me
    left = 1 - others - me
    return me + left/N

def case(N, S):
    SP = [(S[i], i) for i in xrange(N)]
    SP.sort()
    X = float(sum(S))
    newS = [ s/X for (s,i) in SP ]
    print X
    print SP
    print newS
    res = [0]*N
    for i in xrange(N):
        res[SP[i][1]] = casei(N,newS,i)
    return ' '.join( "%.6f" % (100*f) for f in res )

def solve(fin, fout):
    T = int(fin.readline())
    for t in xrange(T):
        R = map(int, fin.readline().strip().split(' '))
        N = R[0]
        S = R[1:]
        fout.write("Case #%i: %s\n" % (t+1, case(N,S)) )
    return True

if __name__ == "__main__":
    import sys
    with open(sys.argv[1],'r') as fin:
        with open(sys.argv[2], 'w') as fout:
            solve(fin, fout)
