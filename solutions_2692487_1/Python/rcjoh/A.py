def absorb(a, others):
    while True:
        old = others[:]
        for m in others:
            if m < a:
                a += m
                others.remove(m)
        if others == old:
            return a, others


def altern(a, others):
    if a == 1: return float('inf')
    ops = 0
    while True:
        others.sort()
        a, others = absorb(a, others)
        if not others:
            return ops
        ops += 1
        others.append(a - 1)


def general(a, others):
    if a == 1:
        return len(others)
    ops = 0
    while True:
        others.sort()
        a, others = absorb(a, others)
        if not others:
            return ops
        # Add
        if 2 * a - 1 > others[0]:
            ops += 1
            others.append(a - 1)
        # Remove
        else:
            ops += 1
            k = others.pop()


def solve_case(a, others):
    return min(general(a, others[:]), altern(a, others[:]))


if __name__ == '__main__':
    import sys
    r = sys.stdin.readline
    t = int(r())
    for i in xrange(t):
        a = int(r().split()[0])
        others = map(int, r().split())
        print 'Case #{0}: {1}'.format(i + 1, solve_case(a, others))
