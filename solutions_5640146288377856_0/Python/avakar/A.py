import sys

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

for t in xrange(pop_int()):
    R = pop_int()
    C = pop_int()
    W = pop_int()
    r = (C // W) * R
    if C % W == 0:
        r += W - 1
    else:
        r += W
    print 'Case #{}: {}'.format(t+1, r)
