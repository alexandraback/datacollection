quaternions = (
    (1, 2, 3, 4),
    (2, -1, 4, -3),
    (3, -4, -1, 2),
    (4, 3, -2, -1)
)

def multiple(x, y):
    if x < 0 and y < 0:
        return multiple(-x, -y)
    if x < 0:
        return -multiple(-x, y)
    if y < 0:
        return -multiple(x, -y)
    return quaternions[x - 1][y - 1]

def switch(c):
    if c == "1":
        return 1
    if c == "i":
        return 2
    if c == "j":
        return 3
    return 4

if __name__ == "__main__":
    casenum = input()
    for caseidx in xrange(1, casenum + 1):
        l, x = map(int, raw_input().split())
        if x > 12:
            x = (x - 12) % 4 + 12
        s = "1" + (raw_input() * x) + "1"
        n = len(s)
        ans = False

        start = [1]
        for i in xrange(1, n):
            start.append(multiple(start[-1], switch(s[i])))
        if start[-1] == -1:
            end = [1]
            for i in xrange(n - 2, -1, -1):
                end.append(multiple(switch(s[i]), end[-1]))
            try:
                cut1 = start.index(switch("i"))
            except:
                cut1 = n
            try:
                cut2 = n - 1 - end.index(switch("k"))
            except:
                cut2 = -1
            if cut1 + 1 < cut2:
                ans = True

        # print start[-1], cut1, cut2, ans, cut1 + 1 < cut2
        print "Case #%d: %s" % (caseidx, "YES" if ans else "NO")
