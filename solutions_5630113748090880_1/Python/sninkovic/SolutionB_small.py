T= int(raw_input())

for t in range(0,T):
    N = int(raw_input())
    a=[]
    counts={}
    for i in range(0,2*N-1):
        ulaz = raw_input().split()
        for u in ulaz:
            br = int(u)
            if br in counts:
                counts[br]=counts[br]+1
            else:
                counts[br]=1

    rez = []
    for k in counts:
        if (counts[k]%2==1):
            rez.append(k)
    rv = sorted(rez)
    print "Case #"+str(t+1)+":"," ".join(map(str,rv))

    
