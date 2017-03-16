task = 'A'
type = 1
attempt = 1

if type == -1:
    inp = open('sample.in', 'r')
    type = 'sample'
elif type==1:
    inp = open('%s-large.in' % (task,))
else:
    inp = open('%s-small-attempt%s.in' % (task, type, attempt), 'r')
outp = open('%s-%s.out' % (task, type), 'w')

T = int(inp.readline()[:-1])
for i in range(T):
    N = int(inp.readline()[:-1])
    s_set = set()
    q = 0
    while len(s_set) < 10 and q < 10 ** 5:
        q += 1
        s_set = s_set.union(set(list(str(q * N))))
    if len(s_set) == 10:
        ans = q * N
    else:
        ans = 'INSOMNIA'
    outp.write("Case #%s: %s\n" % (i + 1, ans))
