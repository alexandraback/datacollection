import sys
input = sys.stdin

def process(A, B):
    if A < 10:
        return 0
    k = 0
    dd = {}
    for x in xrange(A, B+1):
        pk = {}
        pm = {}
        s = str(x)
        p = int(s[0])
        
        for i in xrange(1, len(s)):
            j = s[i:] + s[0:i]
            j = int(j)
            if j > x and j<=B:
                pk[str(x)+'_'+str(j)]  = ''
        k += len(pk.keys())
    return k

T=int(input.readline())
for i in xrange(1,T+1):
    data = input.readline().strip().split(' ')
    A = int(data[0])
    B = int(data[1])
    res = process(A, B)
    print "Case #%s: %s" % (i, res)
