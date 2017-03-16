cases = map(str.strip,list(open('C-small-attempt0.in'))) #'btest.in')))#
cases.pop(0)
def rots(n, aS, bS):
    s = str(n)
    pairs = set()
    for i in xrange(len(s)):
        r = s[i:]+s[:i]
        if r < s and aS <= r and r <= bS:
            #print r,'<',s
            pairs.add((r,s))
    return len(pairs)

out = open('c.out', 'w')
for i,c in enumerate(cases):
    aS,bS = c.split()
    a,b = int(aS),int(bS)
    total = sum(map(lambda n:rots(n,aS,bS),xrange(a,b+1)))
    print a,b,total#,map(rots,xrange(a,b+1))
    out.write('Case #%d: %d\n' % (i+1,total))
out.close()

