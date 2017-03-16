d = [0] * 1000001
d[1] = 1

q = [1]
cur = 0
while cur < len(q):
    now = q[cur]

    if now+1 < 1000001 and d[now+1] == 0:
        d[now+1] = d[now] + 1
        q.append(now+1)

    x = int(str(now)[::-1])
    if d[x] == 0:
        d[x] = d[now] + 1
        q.append(x)

    cur += 1


T = input()

for C in range(1, T+1):
    num_s = raw_input()
    print "Case #%d:" % C, d[int(num_s)]
