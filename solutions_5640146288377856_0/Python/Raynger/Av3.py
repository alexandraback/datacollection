for c in range(int(input())):
    R, C, W = list(map(int, input().split()))
    turns = 0
    a = R * C
    while a > W:
        a -= W
        turns += 1
    turns += (W)
    print("Case #{}: {}".format(c+1, turns))    