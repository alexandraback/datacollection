import math
T = int(raw_input())

for _ in range(T):
    r,t = [int(n) for n in raw_input().split(" ")]
    k = 2*r+1
    delta = math.sqrt(k*k + 8*t)
    n = int((-k+delta)/4)
    T = (2*k+4*(n-1))*n/2
    last = k+4*(n-1)
    if T > t:
        while T > t:
            T-=last
            last-=4
            n-=1
    else:
        last+=4
        while T + last <= t:
            T+=last
            last+=4
            n+=1

    print "Case #%d: %d" % (_+1,n)