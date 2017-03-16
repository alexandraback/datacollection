
from sys import stdin

def find_k(n):
    low = 0
    high = 800
    while low + 1 < high:
        mid = (low + high) / 2
        if mid * (2*mid-1) >= n:
            high = mid
        else:
            low = mid
    return low


def run(l,r,k,tot,top):
    #print l,r,k,tot,top
    if tot == 0:
        if l >= k:
            return 1
        else:
            return 0
    elif l >= top:
        return run(l,r+1,k,tot-1,top)
    elif r >= top:
        return run(l+1,r,k,tot-1,top)
    else:
        return run(l+1,r,k,tot-1,top)+run(l,r+1,k,tot-1,top)



T = int(stdin.readline())
for loop in range(1,T+1):
    n, x, y = [int(x) for x in stdin.readline().split()]
    k = find_k(n)
    #print 'k=', k
    dist = (abs(x) + abs(y)) / 2
    #print 'dist=', dist
    delta = n - k * (2*k-1)
    #print 'delta=', delta
    pri = abs(y) + 1
    #print 'pri=', pri

    ans = 0.0
    if dist > k:
        ans = 0.0
    elif dist < k:
        ans = 1.0
    elif delta >= 2*k+pri:
        ans = 1.0
    elif pri >= 2*k+1 or pri > delta:
        ans = 0.0
    else:
        #print 'delta=',delta
        ans = (0.5**delta)*run(0,0,pri,delta,2*k)
    print 'Case #' + str(loop) + ': ' + str(ans)

