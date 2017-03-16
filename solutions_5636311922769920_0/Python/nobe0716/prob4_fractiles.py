
for t in range(1, int(input().strip()) + 1):
    k, c, s = [int(x) for x in input().strip().split()]
    ans = ""
    if k / c > s:
        ans = "IMPOSSIBLE"
    else:
        s = set()
        arr = []
        while len(s) < k:
            loc = 0
            for i in range(c):
                if len(s) < k:
                    p = list(filter(lambda x: x not in s, range(k)))[0]
                    s.add(p)
                    loc += p * pow(k, c - i - 1)
            arr.append(loc + 1)
        ans = " ".join(map(str, arr))
    print("Case #%d: %s" % (t, ans))

