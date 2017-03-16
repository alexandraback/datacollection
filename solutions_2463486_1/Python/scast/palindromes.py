import bisect
f = [x.strip() for x in open('out4', 'r').readlines()]
pp = []
for x in f:
    p = True
    n = len(x)
    for y in range(n/2+1):
        if x[y] != x[n-1-y]:
            p = False
            break
    if p:  pp.append(int(x))

# t = int(raw_input())
# print pp
# for i in range(t):
#     a,b = raw_input().split()
#     a = int(a)
#     b = int(b)

#     pa = bisect.bisect(pp, a)
#     print pa
#     pb = bisect.bisect(pp, b)
#     print pb
#     print "Case #%d: %d" % (i+1, pb-pa + (1 if (pp[pa] == a or pp[pb] == b) else 0))
