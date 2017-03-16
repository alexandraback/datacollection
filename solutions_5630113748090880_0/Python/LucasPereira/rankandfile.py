t = int(raw_input())
for i in xrange(1, t + 1):
    n = int(raw_input())
    lists = []
    for j in xrange(2 * n - 1):
        tempIn = raw_input().split(" ")
        tempList = []
        for c in tempIn:
            tempList.append(int(c))
        lists.append(tempList)
    heightCount = {}
    for sublist in lists:
        for l in sublist:
            if heightCount.get(l, None):
                heightCount[l] = heightCount[l] + 1
            else:
                heightCount[l] = 1
    ans = []
    for k in heightCount.keys():
        if heightCount[k] % 2 == 1:
            ans.append(k)
    print "Case #{}: {}".format(i, " ".join(str(x) for x in sorted(ans)))
