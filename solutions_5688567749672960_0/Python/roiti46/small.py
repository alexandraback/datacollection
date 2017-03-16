used = [-1] * (10 ** 6 + 1)
used[1] = 1
que = [[1, 1]]
while que:
    a, cnt = que.pop(0);
    if a + 1 <= 10**6 and used[a + 1] == -1:
        used[a + 1] = cnt + 1
        que.append([a + 1, cnt + 1])
    b = int(str(a)[::-1])
    if b <= 10**6 and used[b] == -1:
        used[b] = cnt + 1
        que.append([b, cnt + 1])
        
T = int(raw_input())
for case in xrange(1, T + 1):
    N = int(raw_input())
    ans = used[N]
    print "Case #%d: %d" % (case, ans)
