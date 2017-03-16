for t in range(1,input()+1):
    k=input()
    classes=[list(map(lambda x:int(x)-1,raw_input().split()[1:])) for n in range(k)]
    
    in_loads=[0 for x in range(k)] 
    loads=[]       
    def solve(x):
        for n in classes[x]:
            if loads[n]:return True
            else:
                loads[n]=1
                if(solve(n)):return True
        return False
    res=False
    for x in range(k):
        loads=in_loads[:]
        if(solve(x)):
            res=True
            break
    if(res):
        print "Case #%d: Yes" % (t)
    else:
        print "Case #%d: No" % (t)
    
            