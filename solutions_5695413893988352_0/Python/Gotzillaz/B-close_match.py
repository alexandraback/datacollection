from itertools import product as perm

t = input()
for case in xrange(1,t+1):
    c,j = raw_input().split()
    cq = c.count('?')
    jq = j.count('?')
    ans = ''
    mdif = 1000000
    cl = list(perm(range(10),repeat=cq))
    jl = list(perm(range(10),repeat=jq))
    for cr in cl:
        ct = c
        for m in cr:
            ct = ct.replace('?',str(m),1)
        for jr in jl:
            jt = j
            for m2 in jr:
                jt = jt.replace('?',str(m2),1)
            dif = abs(int(ct)-int(jt))
            if dif < mdif:
                mdif = dif
                ans = ct+" "+jt
    print "Case #%d: %s"%(case,ans)
