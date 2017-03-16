import sys, math

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for i in xrange(cases):
    rt = stdin.pop(0).split(' ')
    t = int(rt.pop())
    r = int(rt.pop())
    n = -1
    while t >= 0:
        t -= r
        r += 1
        t -= r
        r += 1
        n += 1
    print "Case #"+str(i+1)+": "+str(n)
