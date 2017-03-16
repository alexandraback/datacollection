cache = {}

def keyify(a):
    return ''.join(map(str, a))

def splitornot(pancakes):
    if len(pancakes) == 0: return 0
    k = keyify(pancakes)
    if k in cache: return cache[k]

    new = []
    new.append([a - 1 for a in pancakes if a > 1])

    i = -1
    if pancakes[i] > 3:
        for j in xrange(1, pancakes[i]):
            p2 = list(pancakes)
            p2[i] -= j
            p2.append(j)
            p2.sort()
            new.append(p2)
    
    remaining = [splitornot(p) for p in new]
#    print k, remaining
    val = min(remaining) + 1
    cache[k] = val
    return val


t = int(raw_input())
for i in xrange(1, t+1):
    raw_input()
    ps = map(int, raw_input().split())
    ps.sort()

    print 'Case #%d: %d' % (i, splitornot(ps))


