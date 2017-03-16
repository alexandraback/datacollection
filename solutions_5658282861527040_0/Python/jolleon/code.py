
def solve(a, b, k):
    count = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                count += 1
    return count

def readint(f):
    return int(f.readline()[:-1])

def readints(f):
    return map(int, f.readline()[:-1].split())

f = open('blah')

ntests = readint(f)
for case in xrange(ntests):
    a, b, k = readints(f)
    print 'Case #%d: %s' % (case+1, solve(a, b, k))