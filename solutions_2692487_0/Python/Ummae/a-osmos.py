
n = 0
def how_many(c, g):
    a, b = c, g
    if a == 1:
        return a, n
    cnt = 0
    while a <= b:
        a += (a-1)
        cnt += 1
    return a, cnt



T = int(raw_input())
for t in range(T):
    a, n = map(int, raw_input().strip().split())
    ms = map(int, raw_input().strip().split())
    ms.sort()
    exp = []
    na = a
    cnt = 0
    for i in range(n):
        na, cc = how_many(na, ms[i])
        na += ms[i]
        cnt += cc
        exp.append((na, cnt))
    ans = n
    for i in range(n):
        ans = min(ans, exp[i][1] + (n-i-1))
    print 'Case #%d: %d' % (t+1, ans)
