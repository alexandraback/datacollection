from bisect import *

def check(a):
    s1 = str(a)
    s2 = s1[::-1]
    return s1==s2

# Main
t = int(raw_input())

fair = []
for i in range(1,10**7+1):
    if check(i) and check(i*i):
        fair+=[i*i]

for i in xrange(0,t):

    x, y = raw_input().split(' ')
    x, y = int(x), int(y)

    l = bisect_left(fair,x)
    r = bisect_right(fair,y)
    print "Case #%d:" % (i+1), r-l
    
