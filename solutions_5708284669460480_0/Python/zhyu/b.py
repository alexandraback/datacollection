import re


res = []


def dfs(now, a, b, s):
    if len(now) == s:
        cnt = sum(1 for _ in re.finditer(b, now))
        res.append(cnt)
        return

    for ch in a:
        dfs(now + ch, a, b, s)

for cas in xrange(int(raw_input())):
    k, l, s = map(int, raw_input().split())
    a = raw_input()
    b = raw_input()

    if set(b) - set(a):
        print 'Case #{0}: 0.0'.format(cas+1)
    else:
        res = []
        b = '(?={0})'.format(b)
        dfs('', a, b, s)
        print 'Case #{0}: {1}'.format(cas+1, max(res)-sum(res)*1.0/len(res))
