def main():
    T = int(raw_input())
    for te in xrange(1, T+1):
        r, t = raw_input().split()
        r = int(r)
        t = int(t)
        b = 1
        e = 10000000000
        while(b < e):
            m = (b+e+1)/2
            v = (2*r + 1 + 2*(2*(m-1)+r) + 1) * m
            if(v <= 2*t):
                b = m
            else:
                e = m-1

        print "Case #%d: %d" %(te, b)

main()
