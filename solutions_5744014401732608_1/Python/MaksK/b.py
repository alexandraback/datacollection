t = int(input())

for case in range(1, t + 1):
    b, m = map(int, input().split())
    if 2 ** (b - 2) < m:
        print("Case #{}: {}".format(case, "IMPOSSIBLE"))
        continue

    result = [[0] * b for i in range(b)]
    for i in range(1, b):
        for j in range(i + 1, b):
            result[i][j] = 1
    mb = list(bin(m - 1))[2:] + [1]
    result[0] = [0] * (b - len(mb)) + mb

    print("Case #{}: {}".format(case, "POSSIBLE"))
    for line in result:
        print("".join(map(str, line)))
