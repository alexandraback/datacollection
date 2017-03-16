#!/usr/bin/env python

def case(A, B, P):
    best = 1 + B + 1 # press enter now.
    P.append(1)

    prob = 1
    i = 0
    for bc in xrange(A, -1, -1):
        ans = B-A + bc*2 + (1 - prob)*(B + 1) + 1
        print bc, ans
        best = min(ans, best)
        prob *= P[i]
        i+=1
    return best


def solve(fin, fout):
    T = int(fin.readline())
    for t in xrange(T):
        A, B = map(int, fin.readline().strip().split(' '))
        P = map(float, fin.readline().strip().split(' '))
        fout.write("Case #%i: %.6f\n" % (t+1, case(A,B,P)) )
    return True

if __name__ == "__main__":
    import sys
    with open(sys.argv[1],'r') as fin:
        with open(sys.argv[2], 'w') as fout:
            solve(fin, fout)
