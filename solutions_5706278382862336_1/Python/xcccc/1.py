def gcd(a, b):
    if b==0:
	    return a
    return gcd(b, a%b)


f = open("A-large.in")
fo = open("A-large.out", "wb")
T = int(f.readline())
for i in range(T):
    line = f.readline().split("/")
    P = int(line[0])
    Q = int(line[1])
    x = gcd(P, Q)
    P /= x
    Q /= x
    if Q & (Q-1):
        fo.write("Case #%d: %s\n" % (i+1, "impossible"))
    else:
        t = Q
        k = 1
        while t > 0 and P < t/2 and k<=40:
            t /= 2
            k += 1
        if k <= 40:
            fo.write("Case #%d: %d\n" % (i+1, k))
        else:
            fo.write("Case #%d: %s\n" % (i+1, "impossible"))



 
