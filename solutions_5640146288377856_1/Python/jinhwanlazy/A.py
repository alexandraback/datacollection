def solve(R, C, W):
    count = 0
    count += C // W
    space = C % W + W
    if (space == W):
        count += W-1
    else:
        count += W

    return R * count

for case in range(int(input())):
    R, C, W = map(int, input().split())
    print("Case #%d: %s" % (case+1, solve(R, C, W)))
