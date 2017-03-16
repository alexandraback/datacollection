import sys

def parse(l):
    data = l.split()

    n = int(data[0])
    scores = [float(s) for s in data[1:]]

    return n, scores

def solve(n, scores):
    X = sum(scores)

    sscores = sorted(scores)

    y = 1.0

    t = 0.0
    i = 1
    while i < len(sscores):
        if sscores[i] > sscores[i - 1]:
            dt = (sscores[i] - sscores[i - 1]) * i
            if t + dt < X:
                t += dt
            else:
                break
        i += 1

    m = sscores[i - 1] + (X - t) / i

    r = []
    for s in scores:
        if m - s > 0.0:
            r.append((m - s) / X)
        else:
            r.append(0.0)

    return r

if __name__ == "__main__":
    f = open(sys.argv[1])

    N = int(f.readline())

    i = 1
    for j in range(N):

        n, scores = parse(f.readline())

        print "Case #%d: %s" % (i, " ".join("%f" % (100.0 * x) for x in solve(n, scores)))

        i += 1
