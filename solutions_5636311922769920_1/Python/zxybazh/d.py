file = open("D-large.in", "r")
a = file.readlines()
for i in xrange(1, len(a)):
    k, c, s = [int(w) for w in a[i].split(" ")]
    print "Case #%d:" % i,
    step = c
    if (s * c < k):
        print "IMPOSSIBLE"
        continue
    cnt = 0
    while (cnt < k):
        temp = 1
        for i in xrange(c):
            temp += cnt * k ** (c - i - 1)
            cnt += 1
            if (cnt == k): break
        print temp,
    print
