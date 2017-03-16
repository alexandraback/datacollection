from collections import Counter as ct
def f(l):
    #print l
    if len(l)==1:
        return l[0]
    m=min(x[0] for x in l)
    two=filter(lambda x:x[0]==m,l)
#print two,m
    if len(two)==2:
        rest=filter(lambda x:x[0]!=m,l)
        c=ct(two[0][1:]+two[1][1:])
        c-=ct([x[0] for x in rest])
        assert len(c)==1
        return list(c.elements())+f(sorted([x[1:] for x in rest]))
    else:
        m=max(x[-1] for x in l)
        two=filter(lambda x:x[-1]==m,l)
        rest=filter(lambda x:x[-1]!=m,l)
        assert len(two)==2
        c=ct(two[-1][:-1]+two[-2][:-1])
        c-=ct([x[-1]for x in rest])
        assert len(c)==1
        return f(sorted([x[:-1] for x in rest]))+list(c.elements())
for c in range(int(raw_input())):
    n=int(raw_input())
    l=[map(int, raw_input().split()) for i in range(2*n-1)]
    print "Case #{}: {}".format(str(c+1)," ".join(map(str,f(l))))