# f = open('A-large-practice.in')
f = open('C-small-attempt0.in')

import sys
sys.stdout = open('out', 'w')

T = f.readline()
for case in range(int(T)):
    n = f.readline().split()
    w1 = []
    w2 = []
    ll = []
    for i in range(int(n[0])):
        l = f.readline().rstrip('\n').split(' ')
        w1.append(l[0])
        w2.append(l[1])
        ll.append(l)
    
    fakeCount = 0    
    for item in ll:
        if w1.count(item[0]) > 1 and w2.count(item[1]) > 1:
            fakeCount+=1
        
            
    print "Case #"+str(case+1)+":", str(fakeCount)
    
