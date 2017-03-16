import sys, math, random, itertools, collections

N, M = 3, 5

fact = [1]
for i in range(1, 15):
    fact.append(len(fact) * fact[-1])

#sets = [tuple(sorted(x)) for x in itertools.product(range(2, M+1), repeat=N)]
set_priors = collections.Counter()
for s in itertools.combinations_with_replacement(xrange(2, M+1), N):
    set_priors[s] = fact[N] / reduce(lambda x,y:x*y, map(fact.__getitem__, collections.Counter(s).values()), 1)

counts = collections.defaultdict(collections.Counter)
masks = list(itertools.product(range(2), repeat=N))

for s in set_priors:
    for m in masks:
        p = reduce(lambda x,y:x*y, [a for a, b in zip(s, m) if b], 1)
        #print s, m, p
        counts[s][p] += 1

#print counts

prod_counts = collections.defaultdict(dict)
for s, c in counts.iteritems():
    for p, v in c.iteritems():
        prod_counts[p][s] = v

#print prod_counts

def proc(prods):
    probs = dict(set_priors)

    for p in prods:
        for s in probs.keys():
            if s not in prod_counts[p]:
                del probs[s]
            else:
                probs[s] *= prod_counts[p][s]

    #print probs

    max_prob = max(probs.values())
    poss = [p for p in probs if probs[p] == max_prob]
    #print poss
    return poss[0]

if 0:
    R = 100
    K = 7

    print 1
    print R, N, M, K
    for _ in range(R):
        s = [random.choice(xrange(2, M)) for _ in range(N)]
        prods = []
        for _ in range(K):
            m = [random.choice(xrange(2)) for _ in range(N)]
            prods.append(reduce(lambda x,y:x*y, [a for a, b in zip(s, m) if b], 1))
        print ' '.join(map(str, prods + s))

        # print
        # print s, prods
        # print proc(prods)

        # u += sorted(proc(prods)) == sorted(s)
        # v += 1

    #print float(u)/v


f = open(sys.argv[1])
T = int(f.readline())
R, _N, _M, K = map(int, f.readline().split())

u = v = 0

print 'Case #1:'
for i in range(R):
    line = map(int, f.readline().split())

    prods = line[:K]
    #inp = line[K:]
    res = ''.join(map(str, proc(prods)))# + ' ' + ''.join(map(str, sorted(inp)))

    # u += list(proc(prods)) == sorted(inp)
    # v += 1

    print res
    #print 'Case #%d: %s' % (i+1, res)
