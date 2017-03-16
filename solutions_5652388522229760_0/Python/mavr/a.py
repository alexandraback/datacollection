

with open("A-small-attempt0.in", "r") as infile:
    with open("out.txt", "w") as outfile:
        T = infile.readline()
        tests = map(int, infile.read().splitlines())
        for t, n in enumerate(tests):
        #for n in (1, 2, 11, 1692):
            if n==0:
                outfile.write("Case #%d: INSOMNIA\n" % (t+1))
                continue
            seen = set()
            nn = n
            for i in xrange(1, 1000):
                for c in str(nn):
                    seen.add(c)
                #print seen, len(seen)
                if len(seen)==10:
                    break
                nn += n
            outfile.write("Case #%d: %d\n" % (t+1, nn))
    #if len(seen)<10:
    #mx = max(mx, nn/n)
    #if n%1000==0:
    #    print n
        #print nn/n, mx