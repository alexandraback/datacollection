import sys

def solve(R, C, W):
    res = 0
    res += (R - 1) * (C // W)

    res += C // W
    res += 1 if (C % W != 0) else 0
    res += W - 1
    return res


T = int(sys.stdin.readline().strip())
for t in range(T):
        R, C, W = [int(x) for x in sys.stdin.readline().strip().split()]
        res = solve(R, C, W)
        print("Case #{}: {}".format(t+1, res))
