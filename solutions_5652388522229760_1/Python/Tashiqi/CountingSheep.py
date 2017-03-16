n=int(input())
res = []
for i in range(n):
    N=int(input())
    if N==0:
        res+=["Case #" + str(i+1) + ": INSOMNIA"]
    else:
        X=0
        s={'0','1','2','3','4','5','6','7','8','9'}
        while(s!=set()):
            X+=N
            s-=set(str(X))
        res+=["Case #" + str(i+1) + ": " + str(X)]
for x in res:
    print(x)
        
