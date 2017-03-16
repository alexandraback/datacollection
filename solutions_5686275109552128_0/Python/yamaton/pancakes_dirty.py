import sys
import copy

def solve(xs):
    time = 0
    xss = [xs]
    # print(time, xss)

    while [] not in xss:
        xss = tick(xss)
        time += 1
        # print(time, xss)
    return time

def eat(xs):
    return [x - 1 for x in xs if x > 1]

def transfer(xs):
    p = max(xs)
    ys = copy.copy(xs)

    p_half = p // 2
    ys.remove(p)    # remove ONLY the first occurrence
    ys.append(p_half)
    ys.append(p - p_half)
    return ys

def transfer_d9(xs):
    p = max(xs)
    if p >= 9:
        ys = copy.copy(xs)
        p_sub = 3
        ys.remove(p)
        ys.append(p_sub)
        ys.append(p - p_sub)
        return ys
    else:
        return []

def tick(xss):
    yss = [eat(xs) for xs in xss]
    zss = [transfer(xs) for xs in xss]
    dd9 = [ys for ys in (transfer_d9(xs) for xs in xss) if ys]
    return yss + zss + dd9

def parse(txt):
    """
    parse(txt: str) -> [[int]]
    """
    n, rest = int(txt[0]), txt[1:]
    return [[int(s) for s in rest[2*k + 1].split()] for k in range(n)]


if __name__ == '__main__':
    with open(sys.argv[1], "r") as f:
        data = parse([line for line in f if line.rstrip()])

    for (i, diners) in enumerate(data):
        t = solve(diners)
        print("Case #%d: %d" % (i + 1, t))
