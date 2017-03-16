T = int(raw_input())

def solve(k,c,s):
    ntries = (k + c -1) /c
    #print ">",ntries,s
    if ntries > s:
        return "IMPOSSIBLE"
    lsize = k**c
    step = k**(c-1)

    first = 0
    result = []
    for i in xrange(ntries):
        pos = 0
        for step in xrange(c):
            pos = pos*k + first
            first += 1
            first = min(first, k-1)
        result.append(pos)



    return " ".join([str(x+1) for x in result])


for i in xrange(T):
    k,c,s = map(int, raw_input().split())
    print "Case #{0}:".format(i+1),
    print solve(k,c,s)