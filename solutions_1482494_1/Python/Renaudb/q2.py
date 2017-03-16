import sys

def solve(n, ab):
    l1 = sorted(sorted(ab, key=lambda x : x[1], reverse=True), key=lambda x : x[0])
    l2 = sorted(ab, key=lambda x : x[1])

    i1 = 0
    i2 = 0

    score = 0
    round = 0

    while i2 < n:
        if score >= l2[i2][1]:
            score += 1 if l2[i2][2] else 2
            l2[i2][2] = True
            round += 1
            i2 += 1
            continue

        if i1 < n and score >= l1[i1][0]:
            if not l1[i1][2]:
                score += 1
                l1[i1][2] = True
                round += 1
            i1 += 1
            continue

        return "Too Bad"

    return round

if __name__ == "__main__":
    f = open(sys.argv[1])

    N = int(f.readline())

    i = 1
    for j in range(N):
        n = int(f.readline().strip())

        ab = []
        for k in range(n):
            ab.append([int(s) for s in f.readline().strip().split()])
            ab[len(ab) - 1].append(False)

        print "Case #%d: %s" % (i, solve(n, ab))

        i += 1
