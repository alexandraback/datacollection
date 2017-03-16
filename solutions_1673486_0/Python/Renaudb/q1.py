import sys

def parse(l1, l2):
    a = int(l1.split()[0])
    b = int(l1.split()[1])
    p = [float(pi) for pi in l2.split()]

    return a, b, p

def solve(a, b, p):
    sol = [0.0] * (a + 1)

    sol[0] = 1.0
    for i in range(1, a + 1):
        sol[i] = p[i - 1] * sol[i - 1]

    for i in range(a):
        sol[i] = sol[i] * ((a - i) + (b - i) + 1) + (1 - sol[i]) * (((a - i) + (b - i) + 1) + (b + 1))

    sol[a] = sol[a] * (b - a + 1) + (1 - sol[a]) * (b - a + 1 + b + 1)

    best = float(1 + b + 1)
    for i in range(a + 1):
        if sol[i] < best:
            best = sol[i]

    return best

if __name__ == "__main__":
    f = open(sys.argv[1])

    N = f.readline()

    i = 1
    lines = [l for l in f.readlines()]
    for l in range(len(lines) / 2):
        l1 = lines[2 * l].strip()
        l2 = lines[2 * l + 1].strip()

        a, b, p = parse(l1, l2)

        print "Case #%d: %f" % (i, solve(a, b, p))

        i += 1
