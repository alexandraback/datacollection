for c in range(int(input())):
    R, C, W = list(map(int, input().split()))
    turns = 0
    a = C
    while a > W:
        a -= W
        turns += 1
    turns += (W)
    #print(turns)
    #print((W // C) * (R - 1))
    turns += (C // W) * (R - 1)
    print("Case #{}: {}".format(c+1, turns))    