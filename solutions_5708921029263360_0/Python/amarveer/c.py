import sys    

for cases in xrange(int(sys.stdin.readline())):
    J,P,S,K = map(int,sys.stdin.readline().split())
    d1,d2,d3 = {},{},{}
    for i in xrange(1,J+1): d1[i] = 0
    for i in xrange(1,P+1): d2[i] = 0
    for i in xrange(1,S+1): d3[i] = 0
    dress = []
    pairs = {}
    lk = [0 for i in xrange(S+1)]
    comb = min(J*P,J*S,P*J)
    mi = 0
    c = 0
    while min(lk) < K and c <= comb:
        flag = False
        for i in xrange(1,J+1):
            if min(lk) >= K:
                break
            for j in xrange(1,P+1):
                for i1 in lk:
                    if i1 >= K:
                        break
                for k in xrange(1,S+1):
                    if min(lk) >=  K:
                        break

                    if lk[k] < K:
                        if (i,j) not in pairs:
                            pairs[(i,j)] = 0
                        if pairs[(i,j)] < K:
                            pairs[(i,j)] += 1
                            lk[k] += 1
                            dress.append((i,j,k))
                            flag = True
        c += 1

    print "Case #%d: %d"%(cases+1,len(dress))
    for i in dress:
        print i[0],i[1],i[2]
                
                
