from collections import deque
arr = [-1]*(10**6+1)
arr[1] = 1
q = deque([1])

def rev(x):
    y = 0
    while x != 0:
        y = 10*y + x % 10
        x /= 10
    return y

while len(q):
    u = q.popleft()
    for v in [u+1, rev(u)]:
        if v < len(arr) and arr[v] < 0:
            arr[v] = arr[u]+1
            q.append(v)
    # print len(q)

t = int(raw_input())

for kei in xrange(t):
    n = int(raw_input())
    print "Case #%d: %d" % (kei+1, arr[n])
