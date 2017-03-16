def pa(x):
    return str(x) == str(x)[::-1]

li = []
for x in xrange(1, 10**7+1):
    if pa(x) and pa(x**2): li.append(x**2)

def upto(n):
    st = -1
    end = len(li)-1
    while (st < end):
        mid = (st+end+1)/2
        if li[mid] <= n: st = mid
        else: end = mid-1
    return st+1

T = int(raw_input())
for y in xrange(T):
    a,b = map(int,raw_input().split())
    print "Case #%s:" % (y+1), upto(b)-upto(a-1)




