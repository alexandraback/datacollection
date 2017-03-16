
def sieve(C, D, V):
    R = set([0])
    c = 0 
    for d in D:
        for r in list(R):
            if r+d > V:
                break
            R.add(r+d)

    for i in xrange(V+1):
        #print sorted(R)
        #print sorted(set(xrange(V+1)) - R)
        if i not in R:
            c += 1
            #print "Adding {}".format(i)
            for r in list(R):
                R.add(r+i)
    return c

T = int(raw_input())
for t in xrange(1, T+1):
    C, D, V = map(int, raw_input().split())
    d = map(int, raw_input().split())
    #print "{} {} {} - {}".format(C, D, V, d)
    print "Case #{}: {}".format(t, sieve(C, d, V))
