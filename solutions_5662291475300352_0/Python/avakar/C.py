import sys
#all times are *360

def c(hikers, i, j):
    d1, m1 = hikers[i]
    d2, m2 = hikers[j]

    # 1 is faster and stars later
    if m1 < m2 and d1 >= d2:
        return 0

    t1 = (360 - d1) * m1
    t2 = (360 - d2) * m2

    # 1 is faster but starts earlier
    if m1 < m2 and d1 < d2:
        if t1 > t2:
            return 0
        else:
            return 1

    # 1 is slower
    cycles = ((t1 // m2 + m2*360) - (360 - d2)) // (360*m2) - 1
    if d2 <= d1:
        cycles += 1
    return cycles

def crosses(hikers, h):
    total = 0
    for i, (d, m) in enumerate(hikers):
        if i != h:
            total += c(hikers, h, i)
    return total

input = sys.stdin.read().split()

def pop_int():
    return int(input.pop(0))

for t in xrange(pop_int()):
    hikers = []

    N = pop_int()
    for n in xrange(N):
        D = pop_int()
        H = pop_int()
        M = pop_int()
        for i, h in enumerate(xrange(H)):
            hikers.append((D, M+i))
    hikers.sort(key=lambda (d, m): (d, -m))
    res = min(crosses(hikers, i) + i for i in xrange(len(hikers)))

    print 'Case #{}: {}'.format(t+1, res)
