#!/usr/bin/env python3

T = int(input())


for t in range(1, T + 1):
    c, d, v = (int(x) for x in input().split())
    D = (int(x) for x in input().split())
    new_D = []

    result = 0
    possible = [0]

    def extend_possible(pos, coin):
        new_possible = []
        for y in range(c + 1):
            new_possible.extend([coin * y + p for p in pos])
        return sorted(list(set(new_possible)))

    for x in D:
        possible = extend_possible(possible, x)

    def prefix_length():
        for i in range(len(possible)):
            if i != possible[i]:
                return i - 1
        return len(possible) - 1

    while True:
        p = prefix_length()
        if p >= v:
            break
        new_D.append(p + 1)
        possible = extend_possible(possible, p + 1)
        result += 1

    print("Case #{}: {}".format(t, result))

