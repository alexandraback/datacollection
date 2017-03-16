import sys
sys.stdin = open ("B-large.in", "r")
sys.stdout = open ("out.txt", "w")

T = input()
for cas in xrange(1, T+1):
    n = input()
    arr = [map(int, raw_input().split()) for i in xrange(2*n-1)]
    d = [0]*2510
    for i in arr:
        for j in i:
            d[j] += 1
    print "Case #%d: " % cas,
    for i in xrange(2501):
        if d[i] % 2:
            print i,
    print ""
