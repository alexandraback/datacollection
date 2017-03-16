T = int(raw_input())

for t in range(1,T+1):
    s = reversed(raw_input())
    flips = 0
    prev = '+'
    for c in s:
        if c != prev:
            prev = c
            flips += 1
    print "Case #%d: %d" % (t, flips)
