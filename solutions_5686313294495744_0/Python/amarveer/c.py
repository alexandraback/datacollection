import sys

for cases in xrange(int(sys.stdin.readline())):
    N = int(sys.stdin.readline())
    first,second = set(),set()
    l = []
    for i in xrange(N):
        s1,s2 = sys.stdin.readline().strip().split()
        l.append((s1,s2))
        #first.append(s1)
        #second.append(s2)
    c = 0
    vis = set()
    for i in xrange(N):
        for j in xrange(i+1,N):
            f1,l1 = l[i][0],l[i][1]
            f2,l2 = l[j][0],l[j][1]
            #if (f1,l1) in vis or (f2,l2) in vis:
            #    continue
            if (f1,l2) in l and (f1,l2) != (f1,l1) and (f1,l2) != (f2,l2):
                c += 1
                vis.add((f1,l2))
            if (f2,l1) in l and (f2,l1) != (f2,l2) and (f2,l1) != (f1,l1):
                c += 1
                #print i,j
                vis.add((f2,l1))
                #print f1,l2,f2,l1
                #print vis
    print "Case #%d: %d"%(cases+1,c)
        
