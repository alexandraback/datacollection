# [4, 3, 3]
# [9 3 9 12 36 3 36]

from collections import defaultdict

def gen(N,K,low=2):
    if N == 0:
        yield []
    else:
        for x in range(low,K+1):
            for rest in gen(N-1, K, x):
                yield [x] + rest

def works(prod, vals):
    if prod in vals:
        return True
    for val in vals:
        if prod % val == 0:
            if works(prod/val, vals-{val}):
                return True
    return False

def f(prods):
    counts = defaultdict(lambda: defaultdict(int))
    for (a,b,c) in gen(3,5):
        for prod in prods:
            if works(prod, {a,b,c}):
                counts[0][a] += 1
                counts[1][b] += 1
                counts[2][c] += 1
    guess = []
    for var in range(3):
        best = 0
        bestval = 0
        for k in counts[var]:
            if counts[var][k] > best:
                best = counts[var][k]
                bestval = k
        guess.append(bestval)
    return "".join(map(str, guess))

raw_input()
raw_input()
print "Case #1:"
for i in range(100):
    prods = map(int, raw_input().split())
    print f(prods)