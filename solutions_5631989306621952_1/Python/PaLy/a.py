def solve():
    s = input()
    res = ""
    for x in s:
        if len(res) == 0:
            res = x
        elif res[0] < x:
            res = x + res
        else:
            ok = False
            for y in res:
                if y < x:
                    ok = True
                    res = x + res
                    break
                elif y > x:
                    ok = True
                    res = res + x
                    break
            if not ok:
                res = res + x
    return res


t = int(input())
for tt in range(1, t + 1):
    print("Case #" + str(tt) + ":", solve())
