def solve(r, c, w):
    if c % w == 0:
        return (r - 1) * (c // w) + c // w + w - 1
    else:
        return (r - 1) * (c // w) + c // w + w


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        r, c, w = [int(x) for x in input().split()]
        print("Case #%i: %s" % (caseNr, solve(r, c, w)))