#!/usr/bin/python3

def solve():
    k, c, s = map(int, input().split())
    cur = 0
    tiles = []
    for i in range((k - 1) // c + 1):
        v = 0
        for j in range(c):
            v = k * v + cur
            cur += 1
            if cur == k:
                cur = 0
        tiles.append(v)

    if s < len(tiles):
        return "IMPOSSIBLE"
    else:
        return ' '.join(map(lambda x: str(x + 1), tiles))

t = int(input())

for i in range(t):
    print("Case #{}:".format(i + 1), solve())
