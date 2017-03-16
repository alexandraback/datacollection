T = input()
for i in range(1,T+1):
    r, t = raw_input().split()
    r, t = int(r), int(t)
    b, e, a = 0, t, 0
    while b < e:
        a = (b+e+1)/2
        if 2*a*(a+1)+2*a*r-3*a <= t:
            b = a
        else:
            e = a-1
    print "Case #{0}: {1}".format(i,b)
