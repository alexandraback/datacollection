from itertools import combinations
t = input()
for xy in xrange(1,t+1):
    inp = raw_input().split()
    c = int(inp[0])
    d = int(inp[1])
    v = int(inp[2])
    den = [int(i) for i in raw_input().split()]
    has = [0]*(v+1)
    has[0]=1
    for i in den:
        has[i]=1
    all_poss=[]
    for L in range(1, len(den)+1):
        for subset in combinations(den, L):
            all_poss += [sum(subset)]
    for i in all_poss:
        if(i<=v):
            has[i]=1
    ans = 0
    for i in xrange(0,v+1):
        if(has[i]==0):
            ans+=1
            den+=[i]
            has[i]=1
            for L in range(1, len(den)+1):
                for subset in combinations(den, L):
                    all_poss += [sum(subset)]
            for i in all_poss:
                if(i<=v):
                    has[i]=1
    print "Case #"+str(xy)+":",ans
            
            
