import random
def fac(x):
    for i in xrange(2,50):
        if i*i > x:
            return None
        if x%i == 0:
            return i
    return None
def good(s):
    o = []
    for b in xrange(2,11):
        x = int(s,b)
        y = fac(x)
        if not y:
            return None
        o.append(y)
    return o

n, j = map(int,raw_input().split())
l = []
while len(l) < j:
    #print len(l)
    #print l
    s = '1'
    for i in xrange(n-2):
        s += str(random.randint(0,1))
    s += '1'
    g = good(s)
    if g and (s,g) not in l:
        l.append((s,good(s)))
print 'Case #1:'
for p in l:
    print p[0], ' '.join(map(str,p[1]))
