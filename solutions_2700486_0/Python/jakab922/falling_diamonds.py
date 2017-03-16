from math import factorial
from decimal import Decimal

def comb(n, k):
    return (factorial(n)/factorial(k))/factorial(n - k)

def largest_offset(N):
    offset = 0
    modifier = 5

    if N == 1:
        return (0, 0, 5)

    N -= 1

    while N - modifier > 0:
        offset += 2
        N -= modifier
        modifier += 4

    return (offset, N, modifier)

T = int(raw_input().strip())

for i in xrange(T):
    N, X, Y = map(int, raw_input().strip().split(' '))

    max_offset, leftover, hull = largest_offset(N)


    orig_Y = Y
    if X >= 0:
        while Y > 0:
            Y -= 1
            X += 1
    else:
        while Y > 0:
            Y -= 1
            X -= 1

    X = abs(X)

    if X <= max_offset: # Full triangle cover
        print 'Case #%s: %s' % (i + 1, 1.0)
        continue
    elif X > max_offset + 2: # Too far out
        print 'Case #%s: %s' % (i + 1, 0.0)
        continue

    if orig_Y + 1 > leftover: # Y is too large for cover
        print 'Case #%s: %s' % (i + 1, 0.0)
        continue
    else:
        one_side = (hull - 1) / 2
        if leftover >= orig_Y + 1 + one_side: # The other side can be fully built and we have enough to cover this
            print 'Case #%s: %s' % (i + 1, 1.0)
            continue
        if orig_Y == one_side + 1: # Top of the triangle cannot be covered...
            print 'Case #%s: %s' % (i + 1, 0.0)
            continue

        total = 0
        good = 0
        for j in xrange(min(one_side, leftover) + 1):
            if leftover - j > one_side: # Impossible...
                curr = 0
            else:
                curr = comb(leftover, j)

            if orig_Y  + 1 <= j:
                good += curr
            total += curr

        val = float(Decimal(good)/Decimal(total))
        if val < 0.00000001:
            print 'Case #%s: %s' % (i + 1, 0.0)
        else:
            print 'Case #%s: %s' % (i + 1, val)
        continue
