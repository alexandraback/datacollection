import sys
def func(n):
    m=1023
    seen=0
    i=1
    while m!=seen:
        f = n*i;
        r = f
        while r>0:
            seen = seen | (1<<(r%10))
            r/=10

        i+=1
    return (i-1)*n

i=1
n = int(raw_input())
for i in xrange(1,n+1):
    m = int(raw_input())
    if m==0:
        print "Case #%d: INSOMNIA" % i
    else:

        print "Case #%d: %d" % (i,func(m))
    i+=1 
