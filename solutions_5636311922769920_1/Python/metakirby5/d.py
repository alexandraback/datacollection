def has_gold(k, c, s):
    if c * s < k:
        return 'IMPOSSIBLE'

    tiles = []
    cur = 0
    while cur < k:
        t = 0
        for l in xrange(c):
            if cur >= k:
                break
            t += (k ** l) * cur
            cur += 1
        tiles.append(t + 1)
    return ' '.join(map(str, tiles))

if __name__ == '__main__':
    cases = int(raw_input())
    for i in range(cases):
        print("Case #%s: %s" % (i+1, has_gold(*map(int, raw_input().split()))))
