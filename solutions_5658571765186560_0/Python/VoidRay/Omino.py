import sys

# For Small input
def solve(X, R, C):
    # First, check condition on area.
    A = R*C
    q = A/X
    if X*q != A:
        return 'RICHARD'
    
    #======================
    if X == 1:
        return 'GABRIEL'

    if X == 2:
        return 'GABRIEL'

    if X == 3:
        if R == 1 or C == 1:
            return 'RICHARD'

        # If R = 2 => 2 x 3n rectangle can be covered by 3-Ominos
        if R == 2 or C == 2:
            return 'GABRIEL'

        else:
            return 'GABRIEL'

        # Insert more....


    if X == 4:
        if R == 1 or C == 1:
            return 'RICHARD'

        if R == 2 or C == 2:
            return 'RICHARD'

        if R == 3 or C == 3:
            return 'GABRIEL'

        if R >= 4 or C >= 4:
            return 'GABRIEL'

T = int(sys.stdin.readline())
for case in xrange(T):
    X,R,C = map(int, sys.stdin.readline().strip().split(' '))

    print 'Case #%d: %s' % (case + 1, solve(X,R,C))

    

    

    
