__author__ = 'sunghyo.jung'

for t in range(1, int(input().strip()) + 1):
    s = input().strip()
    r = s[0]
    for e in s[1:]:
        if e >= r[0]:
            r = e + r
        else:
            r = r + e
    ans = r
    print("Case #%d: %s" % (t, ans))