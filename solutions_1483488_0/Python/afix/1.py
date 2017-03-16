def normalize(x):
    s = str(x)
    s1 = s[-1] + s[:-1]
    best = x
    while s1 != s:
        if s1[0] != '0' and int(s1) < best: best = int(s1)
        s1 = s1[-1] + s1[:-1]
    return best

norm = [normalize(x) for x in xrange(2000001)]
inp = file("input.txt", "r")
outp = file("output.txt", "w")
test_case = inp.readlines()
for i in xrange(1, int(test_case[0]) + 1):
    a, b = [int(x) for x in test_case[i].split()]
    s = set([])
    d = {}
    for j in xrange(a, b + 1):
        if norm[j] in d:
            d[norm[j]] += 1
        else:
            d[norm[j]] = 1
    ans = 0
    for j in d:
        ans += d[j]*(d[j]-1)/2
    print >> outp, "Case #{0}: {1}".format(i, ans)
    print "Case #{0} - done!".format(i)
print "Success!"
outp.close()
