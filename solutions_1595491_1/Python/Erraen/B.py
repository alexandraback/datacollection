import sys
input = sys.stdin

def get(n):
    k, v = n/3, n%3
    if v == 0:
        a = [k, k, k]
        b = [k-1, k, k+1]
    elif v == 1:
        a = [k, k, k+1]
        b = [k-1, k+1, k+1]
    else: # v = 2
        a = [k, k+1, k+1]
        b = [k, k, k+2]
    if b[0] < 0:
        b = a
    return a, b

def process(N, S, p, t):
    k = 0
    a = {}
    b = {}
    for n in t:
        a[k], b[k] = get(int(n))
        k += 1

    r = 0
    sc = 0
    for i in xrange(k):
        if a[i][-1] >= p:
            r += 1
            continue
        if sc >= S:
            continue
        if b[i][-1] >= p:
            r += 1
            sc += 1
            
    return r

T=int(input.readline())
for i in xrange(1,T+1):
    data = input.readline().strip().split(' ')
    N = int(data[0])
    S = int(data[1])
    p = int(data[2])
    t = data[3:]
    res = process(N, S, p, t)
    print "Case #%s: %s" % (i, res)
