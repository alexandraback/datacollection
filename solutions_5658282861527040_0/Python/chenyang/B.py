for t in range(input()):
    a, b, k = map(int,raw_input().split())
    count = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                count += 1
    print "Case #{}: {}".format(t+1, count)
