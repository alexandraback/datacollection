f = open("B-large.in")
o = open("out.txt", "w")

T = int(f.readline())

for t in range(1,T+1):
    N = int(f.readline())

    a = []
    b = []
    for n in range(N):
        q =f.readline().split()
        a.append(int(q[0]))
        b.append(int(q[1]))

    s = 0
    g = 0
    #print a
    #print b
    while s < N*2:
        m = min(b)
        #print "I have %d, min for b is %d" % (s, m)
        if m <= s:
            g += 1
            x = b.index(m)
            #print "Let's play b[%d] " % x
            b[x]=3000
            if a[x] != 3000:
                a[x]=3000
                s += 2
            else:
                s += 1
            continue


        m = min(a)
        
        #print "I have %d, min for a is %d" % (s, m)
        if m <= s:
            u = [i for i, v in enumerate(a) if v == m]

            c = [b[i] for i in u]
            m = max(c)
            x = u[c.index(m)]

            #print "Let's play a[%d] " % x
            a[x]=3000
            s += 1
            g += 1
            continue
        else:
            break
    #print a
    #print b
    #print "score was: %d, games was: %d" % (s,g)
    o.write("Case #%d: %s\n" % (t, "Too Bad" if s!=N*2 else str(g)))

o.close()
