T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    ints = set()
    for j in range(2 * N - 1):
        row = map(int, raw_input().split())
        for c in row:
            if c in ints:
                ints.remove(c)
            else:
                ints.add(c)
    print "Case #%d: %s" % (i + 1, " ".join(map(str, sorted(list(ints)))))