fin = open("in.in")
fout = open("out.out","w")
data = fin.read().split("\n")
T = int(data.pop(0))
fin.close()
    
for i in range(1, T+1):
    J, P, S, K = data.pop(0).split(' ')
    print ("Case #%d: " % (i,)) +' '.join([J,P,S,K])
    J = int(J)
    P = int(P)
    S = int(S)
    K = int(K)
    t = K * min(J*P, P*S, S*J)
    poss = [(j,p,s) for j in xrange(J) for p in xrange(P) for s in xrange(S)]
    seen = {}
    record = []
    RR = []
    cnt = {}
    cnt1 = {}
    cnt2 = {}
    for j in xrange(J):
        for p in xrange(P):
            cnt[(j,p)] = 0
    for p in xrange(P):
        for s in xrange(S):
            cnt1[(p,s)] = 0
    for j in xrange(J):
        for s in xrange(S):
            cnt2[(j,s)] = 0
    for item in poss:
        seen[item] = False
    for I in poss:
        if not seen[I]:
            if cnt[(I[0],I[1])] + 1 <= K and  cnt1[(I[1],I[2])] + 1 <= K and cnt2[(I[0],I[2])] + 1 <= K:
                RR += [I]
                cnt[(I[0],I[1])] += 1
                cnt1[(I[1],I[2])] += 1
                cnt2[(I[0],I[2])] += 1
    print >>fout, "Case #%d: %d" % (i, len(RR))
    for I in RR:
        print >>fout, "%d %d %d" % (I[0]+1, I[1]+1, I[2]+1)
fout.close()