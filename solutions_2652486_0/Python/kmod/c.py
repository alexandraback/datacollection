import os
import sys
import cPickle
from collections import defaultdict

possibilities = []
def gen_all(l, idx, minval):
    if idx == len(l):
        # print l
        possibilities.append(list(l))
        return
    for i in xrange(minval, M+1):
        l[idx] = i
        gen_all(l, idx+1, i)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    GEN = True

    T = int(f.readline())
    for _T in xrange(T):
        R, N, M, K = map(int, f.readline().split())
        gen_all([0]*N, 0, 2)

        print "Case #1:"

        fn = "%d%d.pkl" % (N, M)
        if not os.path.exists(fn):
            product_counts = []
            for nums in possibilities:
                if nums[-1] == 7:
                    print nums
                products = defaultdict(int)
                for bitmask in xrange(2**N):
                    product = 1
                    minv = 1
                    bad = False
                    for i in xrange(N):
                        if bitmask & (2**i):
                            if nums[i] < minv:
                                bad = True
                                break
                            product *= nums[i]
                        else:
                            minv = nums[i]+1
                    else:
                        products[product] += 1
                product_counts.append(dict(products))
            cPickle.dump(product_counts, open(fn, 'w'))
        else:
            product_counts = cPickle.load(open(fn))

        # print zip(possibilities, product_counts)
        # print len(product_counts)

        for _r in xrange(R):
            products = map(int, f.readline().split())
            assert len(products) == K
            best = 0, 1
            best_idx = -1
            for i in xrange(len(possibilities)):
                nom = denom = 1
                total = sum(product_counts[i].values())
                for p in products:
                    nom *= product_counts[i].get(p, 0)
                    denom *= total
                if nom * best[1] > best[0] * denom:
                    best = nom, denom
                    best_idx = i

            print ''.join(map(str, possibilities[best_idx]))

            # print products
            # print best
            # print


