import sys


def solve(J, P, S, k):
    sol = []
    JP = {}
    JS = {}
    PS = {}
    for s in range(1, S + 1):
        for p in range(1, P + 1):
            PS[(p, s)] = 0
        for j in range(1, J + 1):
            JS[(j, s)] = 0
    for j in range(1, J + 1):
        for p in range(1, P + 1):
            JP[(j, p)] = 0

    sidx = 0
    for j in range(1, J + 1):
        for p in range(1, P + 1):

            for s in range(1, S + 1):
                if JS[(j, s)] == k or JP[(j, p)] == k or PS[(p, s)] == k:
                    continue
                JP[(j, p)] += 1
                JS[(j, s)] += 1
                PS[(p, s)] += 1
                sol.append(' '.join([str(j), str(p), str(s)]))
    return sol


def solve2(J, P, S, k):
    sol = []
    JP = []
    JS = {}
    count = []
    for s in range(1, S + 1):
        count.append(0)
    for j in range(1, J + 1):
        for p in range(1, P + 1):
            JP.append((j, p))
        for s in range(1, S + 1):
            JS[(j, s)] = 0

    s = 0
    for j, p in JP:
        count = 0
        starts = s
        while count < k:
            sol.append(' '.join([str(j), str(p), str(s + 1)]))
            s = (s + 1 % S)
            count += 1
            if s == starts:
                break
    return sol

def main():
    lines = map(lambda s: s.strip(), sys.stdin.readlines()[1:])
    for i, line in enumerate(lines):
        j, p, s, k = map(int, line.split())
        sol = solve2(j, p, s, k)
        print "Case #%d: %d" % (i + 1, len(sol))
        for s in sol:
            print s

if __name__ == '__main__':
    main()
