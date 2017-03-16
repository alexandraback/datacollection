from collections import defaultdict
read_ints = lambda: map(int, raw_input().split())

T = int(raw_input())
vis = set()
ans = None

def go(r, keys, cur): # r: how many remaining...
    global ans
    if r == N:
        ans = list(cur)
    if ans:
        return

    rs = repr((keys, chest))
    if rs in vis:
        return
    vis.add(rs)
    for i in xrange(N):
        if not chest[i] and t[i] in keys and keys[t[i]] > 0:
            keys2 = defaultdict(int, keys)
            keys2[t[i]] -= 1
            for _ in cs[i]:
                keys2[_] += 1
            cur[r] = i + 1
            chest[i] = True
            go(r + 1, keys2, cur)
            chest[i] = False

for no_t in xrange(1, T + 1):
    _, N = read_ints()
    keys = defaultdict(int)
    for _ in read_ints():
        keys[_] += 1

    t = []   # key type needed to open
    cs = []  # key set inside
    for i in xrange(N):
        line = read_ints()
        t.append(line[0])
        cs.append(line[2:])

    ans = None
    vis.clear()
    chest = [False] * N
    go(0, keys, [None] * N)

    if ans:
        print 'Case #%d: %s' % (no_t, ' '.join(map(str,ans)))
    else:
        print 'Case #%d: IMPOSSIBLE' % no_t
