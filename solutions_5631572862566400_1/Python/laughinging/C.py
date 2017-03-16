#fi = open("C-small-attempt0.in", "r")
#fi = open("C.in", "r")
fi = open("C-large.in", "r")
t = int(fi.readline().strip())

for tt in xrange(t):
    N = int(fi.readline().strip())
    a = [0] + map(int, fi.readline().split())
    f = [0 for k in xrange(N + 1)]
    z = 0
    for i in xrange(1, N + 1):
        s = i
        cnt = 1
        v = [0 for k in xrange(N + 1)]
        while v[s] == 0:
            v[s] = cnt
            cnt += 1
            s = a[s]
        z = max(z, cnt - v[s])
        t = i
        cnt = 1
        while True:
            f[t] = max(f[t], v[t])
            if t == s:
                break
            t = a[t]
    s = 0
    for i in xrange(1, N + 1):
        if i < a[i] and i == a[a[i]]:
            s += f[i] + f[a[i]]
    z = max(z, s)
    print "Case #" + str(tt+1) + ":", z














