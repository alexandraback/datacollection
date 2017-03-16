T = int(raw_input())
for t in xrange(1, T+1):
    _, str = raw_input().split()
    needed = 0
    clapped = 0
    for i, c in enumerate(str):
        if clapped < i:
            needed += i - clapped
            clapped = i
        clapped += int(c)
    print "Case #%d: %d" % (t, needed)
