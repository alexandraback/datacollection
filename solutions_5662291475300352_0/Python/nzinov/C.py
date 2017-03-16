t = int(input())
for case in range(t):
    ans = 0
    n = int(input())
    d, h, m = [], [], []
    for i in range(n):
        _d, _h, _m = map(int, input().split())
        d.append(_d)
        h.append(_h)
        m.append(_m)
    count = sum(h)
    if count > 2:
        print("error")
    if count < 2:
        ans = 0
    else:
        if n == 1:
            d = [d[0], d[0]]
            m = [m[0], m[0] + 1]
        tmin = max(*[(360 - d[i]) / m[i] for i in range(2)])
        tmax = min(*[(2*360 - d[i]) / m[i] for i in range(2)])
        if tmax > tmin:
            ans = 0
        else:
            ans = 1
    print("Case #{}: {}".format(case + 1, ans))
