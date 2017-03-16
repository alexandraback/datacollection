
def is_ok(d, x):
    sd = (len(x) - len(str(d))) * '0' + str(d)
    for c0, c1 in zip(sd, x):
        if c1 != '?' and c0 != c1:
            return False
    return True


def sol():
    ans = (2141483647, 2141483647)
    min_abs = 2141483647
    a, b = input().split(' ', 1)
    for i in range(10**len(a)):
        for j in range(10**len(b)):
            if is_ok(i, a) and is_ok(j, b) and abs(i - j) <= min_abs:
                if abs(i - j) == min_abs:
                    if ans[0] == i:
                        if ans[1] > j:
                            ans = (i, j)
                            min_abs = abs(i - j)
                    elif ans[0] > i:
                        ans = (i, j)
                        min_abs = abs(i - j)
                else:
                    ans = (i, j)
                    min_abs = abs(i - j)
    ta = (len(a) - len(str(ans[0]))) * '0' + str(ans[0])
    tb = (len(b) - len(str(ans[1]))) * '0' + str(ans[1])
    return '%s %s' % (ta, tb)

t = int(input())
for i in range(t):
    print("Case #%s: %s" % (i+1, sol()))
