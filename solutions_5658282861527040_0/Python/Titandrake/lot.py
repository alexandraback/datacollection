t = input()

def brute_force(a, b, k):
    c = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                c += 1
    return c

for case in xrange(1,t+1):
    a, b, k = map(int, raw_input().split())
    print "Case #%d: %d" % (case, brute_force(a,b,k))
    