step = [-1] * (10 ** 7 + 1)
step[1] = 1
que = [[1, 1]]
while que:
    a, cnt = que.pop(0);
    if a + 1 <= 10**7 and step[a + 1] == -1:
        step[a + 1] = cnt + 1
        que.append([a + 1, cnt + 1])
    b = int(str(a)[::-1])
    if b <= 10**7 and step[b] == -1:
        step[b] = cnt + 1
        que.append([b, cnt + 1])
        
T = int(raw_input())
for case in xrange(1, T + 1):
    N = int(raw_input())
    que = [[N, 0]]
    used = set([N])
    while que:
        a, cnt = que.pop(0)
        if a <= 10 ** 7:
            ans = step[a] + cnt
            break
        if a + 1 not in used:
            used.add(a - 1)
            que.append([a - 1, cnt + 1])
        b = int(str(a)[::-1])
        if b not in used:
            used.add(b)
            que.append([b + 1, cnt + 1])
    print "Case #%d: %d" % (case, ans)
