
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

def exponentiation_by_squaring(R, X):
    if X == 1:
        return R

    if X % 2 == 0:
        return exponentiation_by_squaring(R*R, X/2)
    else:
        return R*exponentiation_by_squaring(R*R, (X-1)/2)

def solve(X, qs):
    N = len(qs)
    forward = [qs[0]]
    for i in xrange(1, N):
        forward.append(forward[-1]*qs[i])
    R = forward[-1]
    end = exponentiation_by_squaring(R, X)

    if end != quaternion('r', -1):
        return "NO"

    rs = X-1 if X < 8 else 7
    for _ in xrange(rs):
        for i in xrange(N):
            forward.append(forward[-1]*qs[i])

    i = 0
    for i in xrange(len(forward)):
        if forward[i] == quaternion('i', 1):
            break

    for i in xrange(i+1, len(forward)):
        if forward[i] == quaternion('k', 1):
            return "YES"

    return "NO"

T = int(raw_input())
for t in range(1, T+1):
    X = map(int, raw_input().split())[1]
    qs = map(to_quaternion, raw_input().strip())

    print "Case #%d: %s" % (t, solve(X, qs))
