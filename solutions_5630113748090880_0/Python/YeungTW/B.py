t = int(raw_input())

for i in xrange(1, t + 1):
    N = int(raw_input())
    count = [0 for s in xrange(2501)]
    
    for j in xrange(1, 2 * N):
        row = [int(s) for s in raw_input().split(" ")]
        for k in xrange(0, N):
            count[row[k]] = count[row[k]] + 1
    
    list = []
    for j in xrange(1, 2501):
        if (count[j] % 2 != 0):
            list.append(j)
    list.sort()
    print "Case #{}: {}".format(i, " ".join(str(x) for x in list))
