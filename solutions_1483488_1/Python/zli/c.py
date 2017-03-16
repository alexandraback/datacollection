nchoose2=[i*(i-1)/2 for i in xrange(8)]

def perms(s):
    return [int(s[j:]+s[:j]) for j in xrange(len(s))]

for case in range(input()):
    print "Case #"+str(case+1)+":",
    A,B=map(int,raw_input().split())
    skip=[False]*(B+1)
    count=0
    for i in xrange(A,B):
        if skip[i]: continue
        perm=set(p for p in perms(str(i)) if A<=p<=B)
        count+=nchoose2[len(perm)]
        for p in perm:
            skip[p]=True
    print count
