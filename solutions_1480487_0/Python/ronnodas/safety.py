T=int(input())
for t in range(T):
    eps = 10**(-8)
    ss = [int(x) for x in input().split()] 
    N= ss[0]
    del ss[0]
    X = sum(ss)
    ms = [0]*N
    for i in range(N):
        lo,hi = 0.0,1.0
    
        while hi-lo>eps:
            test = (hi+lo)/2
            vote = 0
            score = ss[i]+test*X
            for j in range(N):
                if ss[j]<=score:
                    vote+= (score-ss[j])/X
            if vote<1:
                lo = test
            else:
                hi = test
        ms[i] = (50*(lo+hi))
            
            
    print('Case #',t+1,': ',sep = '',end = '')
    for n in ms:
        print("%.6f" % n,end = ' ')
    print()
        
