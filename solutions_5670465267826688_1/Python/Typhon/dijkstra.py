import qmath
import sys
import operator
q = qmath.quaternion

def find(target, letters, X, start):
    # find the index at which the cumulative product == target.
    # at X == 4, (seq) * (seq) * (seq) * (seq) == 1 for any sequence of i,j,k
    # so we don't need to check further than that.
    L = len(letters)
    end = start + 4 * L
    end = min(end, X * L)
    prod = q(1)
    # debug = []
    for i in xrange(start, end):
        prod *= letters[i % L]
        # debug += [letters[i % L]]
        # print target, debug
        if prod == target: yield i
    
def solve(L, X, letters):
    product = reduce(operator.mul, letters)
    if product ** X != q(-1): 
        # print 'fail check', product, X, product ** X
        return 'NO'

    for i_index in find(q('1i'), letters, X, 0):
        for j_index in find(q('1j'), letters, X, i_index + 1):
            # no need to find k_index, because we know product == -1
            # i * j * (remainder) == -1 so remainder == k
            return 'YES'

    return 'NO'

for n in range(1, int(raw_input()) + 1):
    L, X = map(int, raw_input().split())
    letters = map(q, ['1'+x for x in raw_input()])
    print "Case #%d: %s" % (n, solve(L, X, letters))
    sys.stdout.flush()
