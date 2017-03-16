def ciel(x):
    if (x-int(x)):
        return int(x)+1
    return int(x)

t = int(raw_input().strip())
u = 0
while t>0:
    t-=1
    u+=1
    k, c, s = tuple(map(int, raw_input().strip().split()))
    if ciel(k/float(c))>s:
        print "Case #%d:" %u, "IMPOSSIBLE"
        continue
    elif k<=s:
        print "Case #%d:" %u, " ".join(map(str, range(1, k+1)))
        continue
    if c==1:
        print "Case #%d:" %u, " ".join(map(str, range(1, k+1)))
        continue
    s = [0 for i in range(0, k, c)]
    for i in range(len(s)):
        a = c*i+1
        f = a
        b = c
        while b>1:
            if f>=k:
                a *= k
                b-=1
                f+=1
                continue
            a = f+1+(a-1)*(k)
            f+=1
            b-=1
        s[i] = str(a)
    sol = ' '.join(s)
    print "Case #%d:" %(u), sol
