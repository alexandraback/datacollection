# python3
def solve():
    N=int(input())
    edg=[0] + [int(e) for e in input().split()]
    rem=list(range(1,N+1))

    maxc=0
    bb={}
    while len(rem)>0:
        start=rem[0]
        cur=rem[0]
        seen=set()
        nex=edg[cur]
        length=-1
        
        while cur not in seen:
            if cur in rem:
                rem.remove(cur)
            seen.add(cur)
            cur=nex
            nex=edg[cur]
            length+=1

        if cur == edg[nex]:
            k=min(cur,nex)
            c=-1
            if cur < nex:
                c=0
            else:
                c=1
            
            if k in bb:
                if bb[k][c] < length:
                    bb[k][c]=length                    
                    
            else:
                bb[k]=[1,1]
                bb[k][c]=length
                    
        else:
            count = 1
            while nex != cur:
                count+=1
                nex=edg[nex]

                if maxc < count:
                    maxc=count
    return str(max(maxc, sum([sum(bb[e]) for e in bb]) ))
 
T=int(input());
 
for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())
