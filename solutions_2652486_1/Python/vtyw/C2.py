R = 8000
M = 8
N = 12
from copy import *

K = 12

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

def updatestat(ar):
    allsets = subsets(ar)
    products = [product(x) for x in allsets]
    products = set(products)
    products = list(products)
    products.sort()
    stats.append((ar, products))

def generate(ar):
    if len(ar) >= N:
        updatestat(ar)
        #print ar
        return
    
    smallest = 2
    if len(ar):
        smallest = ar[-1]
    for i in xrange(smallest, M + 1):
        a = deepcopy(ar)
        a.append(i)
        generate(a)

generate([])

T = int(raw_input())
raw_input()
print "Case #1:"
for r in xrange(R):
    prods = [int(x) for x in raw_input().split()]
    for stat in stats:
        if score(stat[1], prods):
            line = reduce(lambda x, y : str(x) + str(y), stat[0])
            print line
            break
        