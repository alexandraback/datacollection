import sys

def searchMissing(values):
    m = dict()
    for vs in values:
        for v in vs:
            m[v] = m.get(v, 0) + 1
    return sorted([int(k) for k,v in m.items() if v & 1 != 0])

def solv(it):
    N = int(next(it))
    values = [next(it).rstrip().split(' ') for i in range(N*2 - 1)]
    missing = searchMissing(values)
    return missing

line = open(sys.argv[1]).readlines()
T = int(line[0])
it = iter(line[1:])
for i in range(1, T+1):
    result = solv(it)
    print("Case #{0}: {1}".format(i, ' '.join([str(r) for r in result])))
