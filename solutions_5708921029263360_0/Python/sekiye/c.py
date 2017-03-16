from multiprocessing import Pool

def solve((J, P, S, K)):
    c = []
    for j in xrange(1, J + 1):
        for p in xrange(1, P + 1):
            for s in xrange(1, S + 1):
                c.append((j, p, s))
    jp = {}
    ps = {}
    sj = {}
    ans = ''
    count = 0
    for j, p, s in c:
        if (j, p) in jp:
            if jp[(j, p)] >= K:
                continue
        if (p, s) in ps:
            if ps[(p, s)] >= K:
                continue
        if (s, j) in sj:
            if sj[(s, j)] >= K:
                continue
        count += 1
        ans += "%d %d %d\n" % (j, p, s)
        if (j, p) in jp:
            jp[(j, p)] += 1
        else:
            jp[(j, p)] = 1
        if (p, s) in ps:
            ps[(p, s)] += 1
        else:
            ps[(p, s)] = 1
        if (s, j) in sj:
            sj[(s, j)] += 1
        else:
            sj[(s, j)] = 1
    return str(count) + '\n' + ans[:-1]

T = int(raw_input())
p = Pool(1)
args = []
for i in range(T):
    J, P, S, K = map(int, raw_input().split())
    args.append((J, P, S, K))
ans = p.map(solve, args)
for i in range(T):
    print 'Case #%d:' % (i + 1), ans[i]
