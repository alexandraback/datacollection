def ink(r, x):
    return x*(r+r+x+x-1)

def f(r,t, low, high):
    ret = -1
    while low<high:
        mid = (low+high)//2
        x=ink(r, mid)
        if x <= t:
            ret = mid
            low = mid+1
        elif x > t:
            high = mid
    return ret

ts = int(raw_input())
for test in range(1,ts+1):
    r, t = map(int, raw_input().split())
    x=f(r,t, 1, t)
    print "Case #%d: %d" % (test, x)
