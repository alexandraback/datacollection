

def flatten(l):
    return [item for sublist in l for item in sublist]

def g(data):
    flat = flatten(data)
    nums = {}
    for n in flat:
        try:
            nums[n] += 1
        except KeyError:
            nums[n] = 1

    r = [k for k, v in nums.iteritems() if v % 2]
    return ' '.join([str(c) for c in sorted(r)])




h = open('b_out.txt', 'w')
f1 = 'test.txt'
f2 = 'bsmall.in'

with open(f2, 'r') as f:
    T = int(f.readline())
    i = 0
    while i < T:
        N = int(f.readline())
        data = [[int(x) for x in f.readline().strip().split()] for _ in xrange(2*N-1)]
        r = g(data)
        print 'Case #%s: %s' %(i+1, r)
        h.write('Case #%s: %s\n' %(i+1, r))
        i += 1

