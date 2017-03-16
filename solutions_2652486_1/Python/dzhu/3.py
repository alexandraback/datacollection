import sys, math, random, itertools, collections, os, cPickle as pickle

N, M = 12, 8

if os.path.exists('prods.pkl'):
    print >>sys.stderr, 'Loading pickled values...'
    set_priors, prod_counts = pickle.load(open('prods.pkl'))
else:
    fact = [1]
    for i in range(1, 20):
        fact.append(len(fact) * fact[-1])

    #sets = [tuple(sorted(x)) for x in itertools.product(range(2, M+1), repeat=N)]
    print >>sys.stderr, 'Enumerating sets...'

    set_priors = collections.Counter()
    counts = collections.defaultdict(collections.Counter)

    for s in itertools.combinations_with_replacement(xrange(2, M+1), N):
        set_priors[s] = fact[N] / reduce(lambda x,y:x*y, map(fact.__getitem__, collections.Counter(s).values()), 1)

    print >>sys.stderr, 'Computing products...'

    for i, s in enumerate(set_priors):
        if not i%100: print >>sys.stderr, i, s
        # for m in masks:
        #     #p = reduce(lambda x,y:x*y, [a for a, b in zip(s, m) if b], 1)
        #     p = 1
        #     for i in xrange(N):
        #         if m&(1<<i): p *= s[i]
        #     #print >>sys.stderr, s, m, p
        #     counts[s][p] += 1

        prods = [1]
        for x in s:
            prods.extend([x*q for q in prods])
        counts[s] = collections.Counter(prods)

    #print counts

    prod_counts = collections.defaultdict(dict)
    for s, c in counts.iteritems():
        for p, v in c.iteritems():
            prod_counts[p][s] = v

    #print prod_counts

    with open('prods.pkl', 'w') as out:
        pickle.dump((set_priors, prod_counts), out, -1)

def proc(prods):
    # print;print
    # print prods
    probs = dict(set_priors)

    for p in prods:
        for s in probs.keys():
            # if s not in prod_counts[p]:
            #     del probs[s]
            # else:
            #     probs[s] *= prod_counts[p][s]
            try:
                probs[s] *= prod_counts[p][s]
            except:
                del probs[s]

        # print p
        # print probs

    #print probs

    max_prob = max(probs.values())
    poss = [p for p in probs if probs[p] == max_prob]
    #print poss
    return poss[0]

if sys.argv[1] == '0':
    R = 500
    K = 12

    print 1
    print R, N, M, K
    for _ in range(R):
        print >>sys.stderr, 'case', _, R
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

else:
    f = open(sys.argv[2])
    T = int(f.readline())
    R, _N, _M, K = map(int, f.readline().split())

    u = v = 0

    print 'Case #1:'
    for i in range(R):
        print >>sys.stderr, 'case', i, R
        line = map(int, f.readline().split())

        prods = line[:K]
        inp = line[K:]
        res = ''.join(map(str, proc(prods)))# + ' ' + ''.join(map(str, sorted(inp)))

        print >>sys.stderr, 'res: %s inp: "%s"' % (res, ''.join(map(str, sorted(inp))))

        u += list(proc(prods)) == sorted(inp)
        v += 1

        print res
        #print 'Case #%d: %s' % (i+1, res)

    print >>sys.stderr, u, v
