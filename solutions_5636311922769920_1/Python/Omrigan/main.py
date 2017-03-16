task = 'D'
type = 1
attempt = 0

if type == -1:
    inp = open('sample.in', 'r')
elif type == 1:
    inp = open('%s-large.in' % (task,))
else:
    inp = open('%s-small-attempt%s.in' % (task, attempt), 'r')
outp = open('%s.out' % (task,), 'w')

T = int(inp.readline()[:-1])
for i in range(T):
    st = inp.readline()[:-1].split(' ')
    K, C, S = int(st[0]), int(st[1]), int(st[2])
    if C * S < K:
        ans = 'IMPOSSIBLE'
    else:
        ans = ''
        cur = 0
        reached = False
        while not reached:
            curc = cur
            cur += 1
            for j in range(C-1):
                if cur >= K:
                    reached = True
                    cur = K - 1
                curc = curc * K
                curc += cur
                cur += 1

            if cur >= K:
                    reached = True
                    cur = K - 1

            ans += '%s ' % (curc + 1,)
    outp.write('Case #%s: %s\n' % (i + 1, ans))
