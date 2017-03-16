from sys import argv

def solution(x):
    return True

def list_possibilities(r, c, w):
    return [(i, j, w) for i in range(r) for j in range (c - w + 1)]

def miss(i0, j0, possibilities):
    acc = []
    for (i, j, w) in possibilities:
        if i0 != i or j0 < j or j0 >= j + w:
            acc.append((i, j, w))
    return acc

with open(argv[1]) as f:
    n = int(f.readline())
    for i in range(n):
        r, c, w = [int(x) for x in f.readline().split()]
        possibilities = list_possibilities(r, c, w)
        mintot = len(possibilities)
        count = 0
        while len(possibilities) > 1:
            count += 1
            for i0 in range(r):
                for j0 in range(c):
                    missed = miss(i0, j0, possibilities)
                    if len(missed) < mintot:
                        mintot = len(missed)
                        opti, optj = i0, j0
            possibilities = miss(opti, optj, possibilities)
        print("Case #%d:" % (i + 1), count + w)
