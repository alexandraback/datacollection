def go(s, i, diff, best):
    nn = len(s)
    if i == nn:
        c = int(''.join(s[:nn/2]))
        j = int(''.join(s[nn/2:]))
        d = abs(c - j)
        # print c, j, d, diff, best
        if d > diff:
            return diff, best
        if d < diff:
            return d, (c, j)
        if c < best[0]:
            return d, (c, j)
        if c == best[0]:
            if j < best[1]:
                return d, (c, j)
        return diff, best
    nd, nb = diff, best
    if s[i] == '?':
        for j in range(10):
            s2 = s[:]
            s2[i] = str(j)
            d, b = go(s2, i+1, diff, best)
            if d < nd:
                nd, nb = d, b
        return nd, nb
    else:
        return go(s, i+1, nd, nb)

n = int(raw_input())
for j in range(n):
    inp = raw_input().strip().split()
    case = list(''.join(inp))
    nums = map(str, go(case, 0, float('inf'), (float('inf'), float('inf')))[1])
    res = [nums[i].zfill(len(inp[i])) for i in range(len(nums))]
    print 'Case #%d: %s' % (j+1, ' '.join(res))
