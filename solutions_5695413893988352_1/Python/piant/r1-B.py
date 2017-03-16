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

def go2(c, j, ci, ji):
    while ci < len(c) and c[ci] == '?' and j[ji] == '?':
        c[ci] = '0'
        j[ji] = '0'
        ci += 1
        ji += 1
    while ci < len(c) and c[ci] != '?' and j[ji] != '?':
        ci += 1
        ji += 1
    while ci < len(c) and ((c[ci] == '?' and j[ji] != '?') or (c[ci] != '?' and j[ji] == '?') or c[ci] == j[ji] != '?'):
        if c[ci] == '?':
            c[ci] = j[ji]
        elif j[ji] == '?':
            j[ji] = c[ci]
        ci += 1
        ji += 1
    # print c, j, ci
    if ci < len(c):
        if c[ci] < j[ji]:
            lo, hi = c, j
        else:
            lo, hi = j, c
        i = ci
        while i < len(c):
            if lo[i] == '?':
                lo[i] = '0'
            if hi[i] == '?':
                hi[i] = '9'
            i += 1
    return c, j

cases = [
    ('1?', '2?'),
    ('?2?', '??3'),
    ('?', '?'),
    ('?5', '?0'),
]

n = int(raw_input())
for i in range(n):
    c, j = raw_input().strip().split()
    res = go2(list(c), list(j), 0, 0)
    res = ' '.join([''.join(s).zfill(len(c)) for s in res])
    # print res
    print 'Case #%d: %s' % (i+1, res)


'''
for j in range(n):
    inp = raw_input().strip().split()
    case = list(''.join(inp))
    nums = map(str, go(case, 0, float('inf'), (float('inf'), float('inf')))[1])
    res = [nums[i].zfill(len(inp[i])) for i in range(len(nums))]
'''
