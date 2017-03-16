'''
Created on May 11, 2014

@author: szalivako
'''

def gcd(a, b):
    while (a != 0 and b != 0):
        if (a > b):
            a = a % b
        else:
            b = b % a
    return a + b

def isP(n):
    while (n > 1):
        if (n % 2 == 0):
            n /= 2
        else:
            return False
    return True
        
T = int(raw_input())
for ti in range(T):
    a, b = map(int, raw_input().split('/'))
    g = gcd(a, b)
    a /= g
    b /= g
    
    if (isP(b)):
        cnt = 0
        while (a < b):
            a *= 2            
            cnt += 1
        print 'Case #' + str(ti + 1) + ': ' + str(cnt)
    else:
        print 'Case #' + str(ti + 1) + ': ' + 'impossible' 
        
    
    
    
    
    
    
