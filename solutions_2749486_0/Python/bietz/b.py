import collections

if __name__ == '__main__':
    T = int(raw_input())

    steps = {}
    bp = collections.defaultdict(dict)
    bp[0][0] = 0
    for size in range(1, 500):
        keys = bp[size-1].keys()
        bps = bp[size]
        for s in keys:
            bps[s+size] = s
            bps[s-size] = s
            if s + size not in steps:
                steps[s+size] = size
            if s - size not in steps:
                steps[s-size] = size

    for t in xrange(1, T+1):
        x, y = map(int, raw_input().split())

        res = []
        size = steps[abs(x) + abs(y)]
        while size > 0:
            s = bp[size][x+y]
            if x + y > s:
                if x < y:
                    y -= size
                    res.append('N')
                else:
                    x -= size
                    res.append('E')
            else:
                if x < y:
                    x += size
                    res.append('W')
                else:
                    y += size
                    res.append('S')
            size -= 1

        assert (x, y) == (0, 0), str((x, y))

        print 'Case #{}: {}'.format(t, ''.join(reversed(res)))

