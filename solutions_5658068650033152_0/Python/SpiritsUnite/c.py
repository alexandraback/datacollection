T = int(raw_input())

def rect(a, b):
    s = 2*(a-2) + 2*(b-2)
    c = s + (a-2)*(b-2)
    return (s, c)

def tri(a, b):
    a, b = max(a,b), min(a,b)
    s = (a-2) + (b-2) + a - 1
    c = s + (a-2)*(a-1)/2 - (a-b)*(a-b+1)/2
    return (s, c)

for C in xrange(T):
    print "Case #" + str(C+1) + ":",
    n, m, k = map(int, raw_input().strip().split())
    if n <= 2 or m <= 2:
        print k
        continue

    ans = 10000000
    for i in xrange(3, n + 1):
        for j in xrange(3, m + 1):
            s, c = rect(i, j)
            if c >= k: ans = min(ans, s)
            else: ans = min(ans, s + k - c)
            s, c = tri(i, j)
            if c >= k: ans = min(ans, s)
            else: ans = min(ans, s + k - c)
    print ans


