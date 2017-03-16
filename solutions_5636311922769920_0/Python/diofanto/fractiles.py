def fractiles(k, c, s):
    tiles = []
    n = 1
    while n <= k**c:
        tiles.append(str(n))
        n += k**(c-1)
    return ' '.join(tiles)

for t in range(int(input())):
    print("Case #{0}: {1}".format(t+1, fractiles(*[int(x) for x in input().split()])))
