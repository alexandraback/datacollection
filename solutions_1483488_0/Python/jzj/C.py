def deal(n,B):
    s=str(n)
    l=len(s)
    se=set()
    for x in xrange(1,l):
        ns=s[x:]+s[:x]
        if ns[0]!='0' and n<int(ns)<=B:
            se.add(int(ns))
    return len(se)

def solve(A,B):
    res=0
    for s in xrange(A,B):
        res+=deal(s,B)
    return res

T = input()
for Case in xrange(1,T+1):
    a,b=map(int,raw_input().split())
    print "Case #"+str(Case)+":", solve(a,b)