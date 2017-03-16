def solve(C, D, V, existing):
    can_be = set()

    for group in xrange(1, 2**D):
        s = 0

        # go through all items in the group.
        x_idx = 0
        x_item = 1

        while x_item <= group:
            if group & x_item == 0:
                x_idx += 1
                x_item <<= 1
                continue

            s += existing[x_idx]

            x_idx += 1
            x_item <<= 1

        if s > V:
            continue

        can_be.add(s)

    left = list(set(range(1, V + 1)) - can_be)

    sol = 0
    left.sort()

    while len(left) > 0:
        m = left[0]
        sol += 1

        new_can = can_be.copy()
        new_can.add(m)
        for i in can_be:
            new_can.add(i + m)

        can_be = new_can
        left = sorted(set(range(1, V + 1)) - can_be)

    return sol

T = int(raw_input())

for i in xrange(T):
    C, D, V = [int(x) for x in raw_input().split()]

    existing = [int(x) for x in raw_input().split()]

    print 'Case #%d: %d' % (i + 1, solve(C, D, V, existing))
