import math
l=[1]
for i in xrange(1,50):
    l.append(l[i-1]*2)


def gcd(a,b):
    while(b):
        a,b=b,a%b
    return a

def solve(a,b):
    d=int(math.log(b,2))
    if(a >= b/2):
        return 1
    else:
        return 1+solve(a,b/2)


for qq in xrange(1,1+int(raw_input())):
    a,b=[int(u) for u in raw_input().strip().split('/')]
    g= gcd(a,b)
    a=a/g
    b=b/g
    
    if(a==1 and b==1):
        print 'Case #%d: 1'%qq

    elif( not (b in l)):
        print 'Case #%d: impossible'%qq
        
    else:
        print 'Case #%d:'% qq,
        print solve(a,b)
        
        
        
