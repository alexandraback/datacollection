def dfs(kb, s, now, res):
    if len(now) == s:
        res.append(''.join(now))
        return
    for i in xrange(len(kb)):
        now.append(kb[i])
        dfs(kb, s, now, res)
        now.pop()

T = int(raw_input())

for ca in xrange(1, T + 1):
    k, l, s = map(int, raw_input().split())
    kb = raw_input()
    tg = raw_input()
    res = []
    dfs(kb, s, [], res)

    total = 0
    mm = 0
    for i in xrange(len(res)):
        tmp = 0
        for j in xrange(s):
            if res[i][j:].startswith(tg):
                tmp += 1
        mm = max(mm, tmp)
        total += tmp
    ans = mm - float(total) / len(res)
    print 'Case #{}: {}'.format(ca, ans)
