from sys import stdin
from collections import Counter, defaultdict

T = int(next(stdin))

for x in range(1, T+1):
    J, P, S, K = map(int, next(stdin).strip().split(" "))

    outfits = set()

    JP = defaultdict(int)
    JS = defaultdict(int)
    PS = defaultdict(int)
    
    for j in range(1, J+1):
        for p in range(1, P+1):
            for s in range(1, S+1):
                if (j, p, s) not in outfits and JP[(j, p)] < K and JS[(j, s)] < K and PS[(p, s)] < K:
                    outfits.add((j, p, s))
                    JP[(j, p)] += 1
                    JS[(j, s)] += 1
                    PS[(p, s)] += 1

    y = len(outfits)

    print("Case #{0}: {1}".format(x, y))

    for o in outfits:
        print(" ".join(map(str, o)))
