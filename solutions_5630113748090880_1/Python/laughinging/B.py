#f = open("B-small-attempt0.in", "r")
f = open("B-large.in", "r")
t = int(f.readline().strip())

for i in xrange(t):
    s = [0 for k in xrange(3000)]
    print "Case #" + str(i+1) + ":",
    N = int(f.readline().strip())
    for j in xrange(N*2-1):
        q = f.readline().split()
        for k in q:
            s[int(k)] ^= 1
    q = [j for j, x in enumerate(s) if x==1]
    print ' '.join([str(j) for j in q])




