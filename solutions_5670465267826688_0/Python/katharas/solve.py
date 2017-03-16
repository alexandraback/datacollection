
from operator import mul

class quaternion:
    def __init__(self, type, mul):
        self.type = type
        self.mul = mul

    def __mul__(self, other):
        if self.type == 'r':
            return quaternion(other.type, self.mul*other.mul)
        elif self.type == 'i':
            if other.type == 'r':
                return quaternion('i', self.mul*other.mul)
            elif other.type == 'i':
                return quaternion('r', -self.mul*other.mul)
            elif other.type == 'j':
                return quaternion('k', self.mul*other.mul)
            else:
                return quaternion('j', -self.mul*other.mul)
        elif self.type == 'j':
            if other.type == 'r':
                return quaternion('j', self.mul*other.mul)
            elif other.type == 'i':
                return quaternion('k', -self.mul*other.mul)
            elif other.type == 'j':
                return quaternion('r', -self.mul*other.mul)
            else:
                return quaternion('i', self.mul*other.mul)
        else:
            if other.type == 'r':
                return quaternion('k', self.mul*other.mul)
            elif other.type == 'i':
                return quaternion('j', self.mul*other.mul)
            elif other.type == 'j':
                return quaternion('i', -self.mul*other.mul)
            else:
                return quaternion('r', -self.mul*other.mul)

    def __repr__(self):
        return "quaternion('%s', %d)" % (self.type, self.mul)

    def __eq__(self, other):
        return self.type == other.type and self.mul == other.mul

    def __ne__(self, other):
        return not self == other

def to_quaternion(s):
    return quaternion(s, 1)

def indexes(qs, q):
    idxs = []
    for idx, qq in enumerate(qs):
        if qq == q:
            idxs.append(idx)
    return idxs

def solve(X, qs):
    q = []
    for i in range(X):
        q.extend(qs)

    N = len(q)
    forward = [q[0]]
    for i in xrange(1, N):
        forward.append(forward[-1]*q[i])

    if forward[-1] != quaternion('r', -1):
        return "NO"

    i = 0
    for i in xrange(N):
        if forward[i] == quaternion('i', 1):
            break

    for i in xrange(i+1, N):
        if forward[i] == quaternion('k', 1):
            return "YES"

    return "NO"

T = int(raw_input())
for t in range(1, T+1):
    X = map(int, raw_input().split())[1]
    qs = map(to_quaternion, raw_input().strip())

    print "Case #%d: %s" % (t, solve(X, qs))
