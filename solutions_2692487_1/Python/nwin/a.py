from sys import stdin
def solve():
    read_ints = lambda: map(int, stdin.readline().split())
    a, n = read_ints()
    b = read_ints()
    if a == 1: return n
    b.sort(reverse=1)
    res = n
    t = 0
    while b:
        if b[-1] < a:
            a += b.pop()
        else:
            a += a - 1
            t += 1
        res = min(res, len(b) + t)
    return res
for i in xrange(int(stdin.readline())):
    print "Case #%d: %d" % (i+1, solve())
