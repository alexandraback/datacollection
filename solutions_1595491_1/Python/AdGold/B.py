cases = map(str.strip,list(open('B-large.in'))) #'btest.in')))#'btest.in')))#'B-small-attempt1.in')))#
cases.pop(0)

_maxS = lambda score:score/3 + (2 if score % 3 == 2 else 1)
maxS = lambda n:_maxS(n) if n > 0 else 0
maxN = lambda score:score/3 + (0 if score % 3 == 0 else 1)

out = open('b.out', 'w')
for i,c in enumerate(cases):
    c = map(int,c.split())
    n,s,p = c[:3]
    scores = c[3:]
    total = 0
    for sc in scores:
        mn = maxN(sc)
        ms = maxS(sc)
        if mn >= p:
            total += 1
            #print 'added 1 for',sc
        elif ms == p and s > 0:
            total += 1
            s -= 1
            #print 'used special for',sc
        #elif ms == p: print 'can\'t do',sc
    
    print cases[i], '\t\t', total
    
    out.write('Case #%d: %d\n' % (i+1,total))
out.close()

