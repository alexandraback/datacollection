T = int(input())

def why(possible, seen):
    counts = {}
    outfit = seen.pop()
    seen.add(outfit)
    j, p, s = outfit
    counts[(j, p, -1)] = 1
    counts[(j, -1, s)] = 1
    counts[(-1, p, s)] = 1

    while True:
        for outfit in possible:
            if outfit in seen:
                continue
            j, p, s = outfit
            if counts.get((j, p, -1), 0) >= K:
                continue
            if counts.get((j, -1, s), 0) >= K:
                continue
            if counts.get((-1, p, s), 0) >= K:
                continue

            break
        else:
            break

        possible.remove(outfit)
        seen.add(outfit)

        if (j, p, -1) not in counts:
            counts[(j, p, -1)] = 0
        if (j, -1, s) not in counts:
            counts[(j, -1, s)] = 0
        if (-1, p, s) not in counts:
            counts[(-1, p, s)] = 0

        counts[(j, p, -1)] += 1
        counts[(j, -1, s)] += 1
        counts[(-1, p, s)] += 1

    return seen


for t in range(1, T+1):
    J, P, S, K = map(int, input().split())

    possible = set()
    for j in range(J):
        for p in range(P):
            for s in range(S):
                possible.add((j, p, s))

    maxseen = set()
    for outfit in possible:
        seen = why(possible.copy(), set([outfit]))
        if len(seen) > len(maxseen):
            maxseen = seen

    seen = maxseen

    print('Case #{}: {}'.format(t, len(seen)))
    for j, p, s in seen:
        print('{} {} {}'.format(j+1, p+1, s+1))


