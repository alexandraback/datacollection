from collections import deque

def rev(n):
    v = 0
    while n > 0:
        v = 10*v + n%10
        n /= 10
    return v

#steps = [-1 for i in xrange(10**6+1)]
#steps[1] = 1
#steps_left = 10**6 - 1
#d = deque([(1, 1)])
#while steps_left > 0:
#    p, t = d.popleft()
#    for nx in (p+1, rev(p)):
#        if nx > 10**6:
#            continue
#        if steps[nx] == -1:
#            steps[nx] = t+1
#            steps_left -= 1
#            d.append((nx, t+1))

T = int(raw_input())

def solve(N):
    if N == 1:
        return 1
    steps = {}
    steps[1] = 1
    d = deque([(1,1)])
    while True:
        p, t = d.popleft()
        for nx in sorted([p+1, rev(p)],reverse=True):
            if nx == N:
                return t+1
            if nx not in steps:
                steps[nx] = t+1
                d.append((nx, t+1))

for case in xrange(1, T+1):
    N = int(raw_input())
    print "Case #{}: {}".format(case, solve(N))
