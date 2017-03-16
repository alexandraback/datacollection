T=int(raw_input())
for t in range(T):
    K,C,S=map(int,raw_input().split())
    ans=[]
    for i in range (0,K,C):
        pos=i
        L=K
        for j in range(1,C):
            pos = pos*K+min(i+j,K-1)
        ans.append(pos+1)
    print "Case #%d:" % (t+1),
    if len(ans) > S:
        print "IMPOSSIBLE"
    else:
        for a in ans:
            print a,
        print

