# A

import sys

def getline():
    return sys.stdin.readline().strip()
    
    
def run(a, b, p):
    rc = list( [0]*(a+2) )
    for i in range(2 ** a):
        rp = 1
        
        c = list( [0]*(a+2) )
        
        # keep typing
        c[0] = b - a + 1
        if i != 0: c[0] += b + 1
        
        # press enter right away
        c[1] = b + 2
        
        # press 1 or more times backspace
        for k in range(a):
            c[k+2] = 2 * (k+1) + b-a + 1
            if (i>>(k+1)) != 0:
                c[k+2] += b+1
        
        for k in range(a):
            if i&(1<<k):  # error
                rp *= 1 - p[a-k-1]
            else:
                rp *= p[a-k-1]
        
        #print c, rp
        for k in range(len(rc)):
            rc[k] += c[k] * rp
    #print rc
    return min(rc)


n = int(getline())

for id in range(1, n+1):
    print 'Case #%d:' % id,
    
    (a, b) = map(int, getline().split(' '))
    p = map(float, getline().split(' '))
    
    print '%.6f' % run(a, b, p)
    
