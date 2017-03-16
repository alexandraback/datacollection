R = 100
M = 5
N = 3
K = 7

stats = []

def subsets(s):
    return reduce(lambda z, x: z + [y + [x] for y in z], s, [[]])

def product(s):
    if not s: return 1
    return reduce(lambda x, y: x * y, s)

def score(products, klist):
    for i in klist:
        if i not in products:
            return 0
    return 1

for i in xrange(2, M + 1):
    for j in xrange(2, M + 1):
        for k in xrange(2, M + 1):
            if j < i or k < i or k < j:
                continue
            allsets = subsets([i, j, k])
            products = [product(x) for x in allsets]
            products = set(products)
            products = list(products)
            products.sort()
            #print "%d %d %d: %s" % (i, j, k, products)
            stats.append(([i, j, k], products))

T = int(raw_input())
raw_input()
print "Case #1:"
for r in xrange(R):
    prods = [int(x) for x in raw_input().split()]
    for stat in stats:
        if score(stat[1], prods):
            print "%d%d%d" % (stat[0][0], stat[0][1], stat[0][2])
            break