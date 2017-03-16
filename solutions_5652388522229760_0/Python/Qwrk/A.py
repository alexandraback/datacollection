
def solve(n):
    x = set(str(n))
    y = 0
    while len(x) != 10:
        y += 1
        x |= set(str(n * y))
    return n * y

if __name__ == "__main__":
    t = int(input())
    for case in range(1, t + 1):
        c = int(input())
        if c != 0:
            print("Case #%d: %s" % (case, solve(c)))
        else:
            print("Case #%d: INSOMNIA" % case)