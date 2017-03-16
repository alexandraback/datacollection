t = int(input())

for curt in range(1, t + 1):
    k, c, s = map(int, input().split())
    if c * s < k:
        print("Case #%d: IMPOSSIBLE" % curt)
    else:
        d = 0
        ans = set()
        for i in range(s):
            z = 0
            for j in range(c):
                z = z * k + d
                if d < k - 1:
                    d += 1
            z += 1
            ans.add(z)
        print("Case #%d:" % curt, " ".join(map(str, ans)))