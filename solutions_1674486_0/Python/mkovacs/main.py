
import numpy as np

def check(A):
    n = A.shape[0]

    B = np.matrix(A)
    S = np.matrix(A)
    for p in range(n):
        B *= A
        S += B

    for i in range(n):
        for j in range(n):
            if S[i, j] > 1:
                return "Yes"

    return "No"

def testcase(tc):
    n = int( raw_input() )
    A = np.matrix( np.zeros([n, n]) )
    
    for i in range(n):
        vs = raw_input().split()
        for s in vs[1:]:
            j = int(s) - 1
            A[i, j] = 1

    res = check(A)

    print 'Case #%s: %s' % (tc, res)

def main():
    t = int( raw_input() )
    for i in range(t):
        testcase(i+1)

if __name__ == '__main__':
    main()
