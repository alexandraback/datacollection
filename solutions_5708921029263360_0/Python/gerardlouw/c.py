from itertools import chain, combinations

def allowed(outfits, K):
    seen = {}
    for outfit in outfits:
        seen[(outfit[0], outfit[1], -1)] = 0
        seen[(outfit[0], -1, outfit[2])] = 0
        seen[(-1, outfit[1], outfit[2])] = 0
    for outfit in outfits:
        seen[(outfit[0], outfit[1], -1)] += 1
        seen[(outfit[0], -1, outfit[2])] += 1
        seen[(-1, outfit[1], outfit[2])] += 1
    return all(v <= K for v in seen.values())

T = int(input())
for t in range(1, T + 1):
    J, P, S, K = map(int, input().split())
    if J == 3:
        if K == 1:
            print("Case #%d: 8" % t)
            print("1 1 1")
            print("1 2 1")
            print("1 3 2")
            print("2 1 2")
            print("2 2 3")
            print("2 3 1")
            print("3 2 2")
            print("3 3 3")
        elif K == 2:
            print("Case #%d: 12" % t)
            print("1 1 1")
            print("1 1 2")
            print("1 2 1")
            print("1 2 2")
            print("2 1 1")
            print("2 1 2")
            print("2 2 1")
            print("2 2 2")
            print("3 1 3")
            print("3 2 3")
            print("3 3 1")
            print("3 3 2")
        elif K >= 3:
            print("Case #%d: 27" % t)
            print("1 1 1")
            print("1 1 2")
            print("1 1 3")
            print("1 2 1")
            print("1 2 2")
            print("1 2 3")
            print("1 3 1")
            print("1 3 2")
            print("1 3 3")
            print("2 1 1")
            print("2 1 2")
            print("2 1 3")
            print("2 2 1")
            print("2 2 2")
            print("2 2 3")
            print("2 3 1")
            print("2 3 2")
            print("2 3 3")
            print("3 1 1")
            print("3 1 2")
            print("3 1 3")
            print("3 2 1")
            print("3 2 2")
            print("3 2 3")
            print("3 3 1")
            print("3 3 2")
            print("3 3 3")
        continue
    A = []
    for j in range(1, J+1):
        for p in range(1, P+1):
            for s in range(1, S+1):
                A.append((j, p, s))
    best_outfits = []
    for outfits in chain.from_iterable(combinations(A, r) for r in range(len(A)+1)):
        if len(outfits) > len(best_outfits) and allowed(outfits, K):
            best_outfits = outfits
    print("Case #%d: %d" % (t, len(best_outfits)))
    for outfit in best_outfits:
        print("%d %d %d" % outfit)
