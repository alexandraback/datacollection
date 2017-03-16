task = 'B'
type = 0
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
    a = inp.readline()[:-1]
    prev = '+'
    ans = 0
    for c in reversed(a):
        if c != prev:
            ans += 1
            prev = c
    outp.write("Case #%s: %s\n" % (i+1, ans))
