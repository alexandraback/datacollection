def do(r, t):
    i = int((((2 * r - 1) * (2 * r - 1) + 8 * t) ** 0.5 - 2 * r + 1) / 4) - 1
    while 2 * i * i + (2 * r - 1) * i - t <= 0:
        i += 1
    return i - 1

T = int(raw_input())

for s in xrange(T):
    k = raw_input().split()
    r = int(k[0])
    t = int(k[1])
    print "Case #%d: %d" % (s + 1, do(r, t))
