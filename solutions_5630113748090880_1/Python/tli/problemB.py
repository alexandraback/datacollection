n = input()

for i in xrange(n):
    m = input()
    counts = [0 for k in xrange(2501)]
    for j in xrange(2 * m - 1):
        heights = map(int, raw_input().split(" "))
        for h in heights:
            counts[h] += 1

    print "Case #" + str(i + 1) + ":",
    for k in xrange(len(counts)):
        if counts[k] % 2 == 1:
            print k,
    print

