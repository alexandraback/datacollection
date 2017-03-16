
def solve(k, c, s):
    if k == 1: return [1]
    p = pow(k, c)
    return range(1, p + 1, (p - 1) // (k - 1))


if __name__ == "__main__":
    t = int(input())
    for case in range(1, t + 1):
        k, c, s = map(int, input().split())
        print("Case #%d:" % case, *solve(k, c, s))