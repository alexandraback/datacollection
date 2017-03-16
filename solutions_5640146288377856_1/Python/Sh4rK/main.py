def solve(R, C, W):
    cn = C // W
    if C % W == 0:
        return cn * R + W - 1
    else:
        return cn * R + W


tcnum = int(input())

for tc in range(1, tcnum+1):
    R, C, W = map(int, input().split())
    print("Case #{}: {}".format(tc, solve(R, C, W)))