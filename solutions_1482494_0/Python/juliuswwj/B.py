# B

import sys

def getline():
    return sys.stdin.readline().strip()
    
    
def run(level):
    star = 0
    c = list([0]*len(level))
    k = 0
    cok = 0
    while True:
        ok = k

        for i in range(len(level)):
            if c[i] == 0:
                if star >= level[i][1]:
                    star+=2
                    c[i] = 2
                    k += 1
                    cok += 1
                    #print 'do %d.2 %d' % (i, star)
                    break
                    
        if ok != k: continue

        for i in range(len(level)):
            if c[i] == 1:
                if star >= level[i][1]:
                    star+=1
                    c[i] = 2
                    k += 1
                    cok += 1
                    #print 'do2 %d.2 %d' % (i, star)
                    break
        if ok != k: continue            
        
        for i in range(len(level)):
            if c[i] == 0:
                if star >= level[i][0]:
                    star+=1
                    c[i] = 1
                    k += 1
                    #print 'do %d.1 %d' % (i, star)
                    break
        if ok != k: continue
                    
        if cok == len(level): break
        return 'Too Bad'
        
    return k

n = int(getline())

for id in range(1, n+1):
    print 'Case #%d:' % id,
    
    n = int(getline())
    level = list()
    for i in range(n):
        level.append(map(int, getline().split(' ')))
    
    print run(level)
    
