import math

def is_square(x):
    if x == 1:
        return x
    for i in xrange(x/2+1):
        if i*i == x:
            return i
    return None

T = int(raw_input())

for t in range(T):
    A, B = [int(i) for i in raw_input().split()]
    
    count = 0
    for n in range(A, B+1):
        sn = str(n)
        if sn == sn[::-1]: # fair
            sqn = is_square(n)
            if sqn:
                ssqn = str(sqn)
                if ssqn == ssqn[::-1]:
                    count += 1                
    
    print 'Case #%d: %d' % (t+1, count)            
                        
                        
    
