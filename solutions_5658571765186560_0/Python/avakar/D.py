import sys

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

def gab(X, R, C):
    if X > 6:
        return False
    if R*C % X:
        return False

    if R > C:
        R, C = C, R

    min_sizes = {
        1: (1, 1),
        2: (1, 2),
        3: (2, 3),
        4: (3, 4),
        5: (4, 5),
        6: (4, 6),
        }

    rmin, cmin = min_sizes[X]
    return R >= rmin and C >= cmin

for t in xrange(pop_int()):
    X = pop_int()
    R = pop_int()
    C = pop_int()

    if gab(X, R, C):
        print 'Case #{}: GABRIEL'.format(t+1)
    else:
        print 'Case #{}: RICHARD'.format(t+1)
