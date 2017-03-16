
def solve(n):
    n += '+'
    r = 0
    for i, j in zip(n, n[1:]):
        r += i != j
    return r

if __name__ == "__main__":
    t = int(input())
    for case in range(1, t + 1):
        print("Case #%d: %d" % (case, solve(input())))
