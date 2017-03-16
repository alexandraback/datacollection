M = 10000
d = [100000000000000000 for _ in range(M)]
d[1] = 1

for i in range(1, M - 1):
    d[i + 1] = min(d[i + 1], d[i] + 1)
    r = int(str(i)[::-1])
    if r < M:
        d[r] = min(d[r], d[i] + 1)

p = [0, 0, 0, 91, 901, 9901, 99001, 999001, 9990001, 99990001, 999900001, 9999900001, 99999000001, 999999000001,
     9999990000001, 99999990000001, 999999900000001]
q = [0, 0, 0, 201, 1101, 11001, 101001, 1010001, 10010001, 100100001, 1000100001, 10001000001, 100001000001,
     1000010000001, 10000010000001, 100000100000001]


def main():
    x = int(input())
    res = 0
    while x >= M:
        s = str(x)
        l = len(s)
        if x < q[l]:
            res += x - p[l]
            x = p[l]
        else:
            xx = s[:l // 2] + (l - 1) // 2 * '0' + '1'
            if int(xx) > x:
                xx = str(int(s[:l // 2])-1) + (l - 1) // 2 * '0' + '1'
            res += x - int(xx)
            if int(xx) == q[l]:
                res += 1
                res += int(xx[::-1]) - p[l]
                x = p[l]
            else:
                res += 1
                x = int(xx[::-1])
    return d[x] + res


if __name__ == '__main__':
    # print('\n'.join(str((i, d[i])) for i in range(2, M) if d[i] < d[i - 1] + 1))
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + str(main()))
