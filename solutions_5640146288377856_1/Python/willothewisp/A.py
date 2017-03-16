def solve(R, C, W):
    if C % W == 0:
        return R*(C//W) + W-1
    return R*(C//W) + W

T = int(input())
for tc in range(1, T+1):
    R, C, W = map(int, input().split())
    print("Case #{}: {}".format(tc, solve(R, C, W)))
