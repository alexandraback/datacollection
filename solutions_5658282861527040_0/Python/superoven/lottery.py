def gl(f, splitchar=' '):
    return map(f, raw_input().split(splitchar))

def g(f):
    return f(raw_input())

t=g(int)
for ind in xrange(t):
    a,b,k=gl(int)
    count = 0
    for i in xrange(a):
        for j in xrange(b):
            if (i&j < k):
                count += 1
    print "Case #%d:" % (ind+1),count
    
