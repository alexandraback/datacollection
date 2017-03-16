t = int(raw_input())
for i in xrange(1, t + 1):
    n = int(raw_input())
    seen = [0] * 10
    ans = "INSOMNIA"
    for j in xrange(1,1000):
        temp = j * n
        for c in str(temp):
            seen[int(c)] += 1
        if not 0 in seen:
            ans = temp
            break
    print "Case #{}: {}".format(i, ans)
