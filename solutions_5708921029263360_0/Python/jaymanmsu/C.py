from collections import defaultdict

T = int(raw_input().strip())

for t in range(T):
    J,P,S,K = map(int,raw_input().strip().split(' '))
    score = lambda jj,pp,ss:(jj+1) + (pp+1)*(J+1) + (ss+1) * (J+1)*(P+1)
    unscore = lambda sc: ((sc % ((J+1))), ((sc/(J+1)) % (P+1)), (sc/((J+1)*(P+1))))
    

    worn = set()
    
    combos = defaultdict(int)
    count = 0
    cjp = [[0 for x in range(P)] for y in range(J)]
    cjs = [[0 for x in range(S)] for y in range(J)]
    cps = [[0 for x in range(S)] for y in range(P)]
    a=[]
    #print t+1,J,P,S,K
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(S):
                #print j,p,s,score(j,p,-1),score(j,-1,s),score(-1,p,s),combos
                #if (combos[score(j,p,-1)] == K) or (combos[score(j,-1,s)] == K) or (combos[score(-1,p,s)] == K):
                if (cjp[j][p] == K) or (cjs[j][s] == K) or (cps[p][s] == K):
                    continue
                count += 1
                combos[score(j,p,-1)] += 1
                combos[score(j,-1,s)] += 1
                combos[score(-1,p,s)] += 1
                cjp[j][p]+=1
                cjs[j][s]+=1
                cps[p][s]+=1
                a.append(' '.join((str(j+1),str(p+1),str(s+1))))
                worn.add(score(j,p,s))
    print "Case #%d: %d" % (t+1, count)
    for b in a:
        print b
    #for s in worn:
    #    print "%d %d %d" % unscore(s)
    
    