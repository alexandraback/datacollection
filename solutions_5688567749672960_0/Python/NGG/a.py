import sys, os

tn = int(sys.stdin.readline())

dpt = [0 for i in xrange(1000001)]
dpt[0] = 0
dpt[1] = 1
for i in xrange(2, 1000001):
    dpt[i] = 1+dpt[i-1]
    if (i%10) != 0:
        j = int(''.join(reversed(str(i))))
        if j < i:
            dpt[i] = min(dpt[i], 1+dpt[j])

#print dpt[1:25]

for ti in xrange(1, tn+1):
    n = int(sys.stdin.readline())
    #print int(''.join(reversed(str(n))))
    print 'Case #{0}:'.format(ti), dpt[n]
