# f = open('A-large-practice.in')
f = open('C-small-attempt0.in')

import sys
sys.stdout = open('out', 'w')

def check(new, res, kk):
    c1 = 0
    c2 = 0
    c3 = 0
    for item in res:
        if item[0] == new[0] and item[1] == new[1]:
            c1 += 1
        if item[0] == new[0] and item[2] == new[2]:
            c2 += 1
        if item[1] == new[1] and item[2] == new[2]:
            c3 += 1 
    return c1<kk and c2<kk and c3<kk

T = f.readline()
for case in range(int(T)):
    l = f.readline().split()
    l = map(int, l)
    K = l[3]
    l1 = range(l[0])
    l2 = range(l[1])
    l3 = range(l[2])
    
    res = []
    
    for i1 in l1:
        for i2 in l2:
            for i3 in l3:
                new = [i1,i2,i3]
                if check(new, res, K):
                    res.append(new)
            
    print "Case #"+str(case+1)+":", len(res)
    for r in res:
        rr = [x+1 for x in r]
        print ' '.join(map(str,rr))
    
