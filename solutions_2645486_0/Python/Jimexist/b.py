cache = {}

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        cache.clear()
        E, R, N = [int(j) for j in f.readline().strip().split()]
        acts = [int(j) for j in f.readline().strip().split()]
        assert len(acts) == N
        #print E, R

        def solve(e, acts, level=0):
            if not acts or e == 0:
                return 0
            if (e, tuple(acts)) in cache:
                return cache[(e, tuple(acts))]
            l = []
            for ee in xrange(e+1):
                c_gain = acts[0] * ee
                left = min(e-ee+R,E)
                gain = solve(left, acts[1:], level+1)
                l.append((gain+c_gain, ee, gain))
            result, max_ee, max_gain = max(l, key=lambda x: x[0])
            #print '\t'*level, result, max_ee, max_gain, acts
            cache[(e, tuple(acts))] = result
            return result

        print "Case #{0}: {1}".format(i+1, solve(E, acts))
        #print cache

if __name__ == '__main__':
    with open('B-small-attempt0.in') as f:
        main(f)