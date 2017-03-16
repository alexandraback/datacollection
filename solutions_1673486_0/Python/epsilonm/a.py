import operator
def fun(a,b,probs):
    val = a+1+b+1
    p = 1
    m=val
    for i in xrange(a,-1,-1):
        if i != a:
            p *= probs[a-i-1]
        r = 2*i + b + 1
        m = min(m,r*p + (1-p)*(1+r+b))
    return m-a



tests = int(raw_input())

for i in xrange(tests):
    a,b = map(int, raw_input().split(' '))
    probs = map(float, raw_input().split(' '))
    print 'Case #'+str(i+1)+':', (fun(a,b,probs))
    
