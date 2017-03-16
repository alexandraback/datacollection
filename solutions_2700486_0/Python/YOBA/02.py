for i in range(int(input())):
    n, x, y = tuple(map(int, input().split()))
    x = abs(x)

    base = x + y - 1
    count = (2 + (base - 1)) // 2 * base

    x = [0.0] * (base + 1) + [1.0]
    if count >= n:
        ans = 0.0
    elif n - count >= (base + 1) * 2 + 1:
        ans = 1.0
    else:
        if y == base + 1:
            ans = 0.0
        else:
            extra = n - count
            if extra > base + 1:
                for j in range(extra - base - 1):
                    x[-1 - j - 1] = 1.0
                extra = extra - base - 1

            for _ in range(extra):
                for j in range(base + 1):
                    if x[j + 1] != 0.0:
                        x[j] = x[j + 1] * (1 - (1 - x[j]) * 0.5)

            ans = x[-2 - y]

    print("Case #{}: {}".format(i + 1, ans))
