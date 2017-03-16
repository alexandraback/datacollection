
import sys

class Quat:
    def __init__(self, sign, ind):
        self.sign = sign
        self.ind = ind

    def __mul__(self, o):
        nsign = self.sign ^ o.sign
        if self.ind == 0 or o.ind == 0:
            return Quat(nsign, self.ind + o.ind)
        else:
            if self.ind == o.ind:
                return Quat(not nsign, 0)
            else:
                nind = (2-(self.ind + o.ind))%3 + 1
                if (o.ind-self.ind)%3 != 1:
                    nsign = not nsign
                return Quat(nsign, nind)

    def __neg__(self):
        return Quat(not self.sign, self.ind)

    def __pow__(self, exp):
        if self.ind == 0:
            if self.sign:
                nsign = exp % 2 != 0
            else:
                nsign = False
            return Quat(nsign, 0)
        else:
            exp %= 4
            if exp % 2 == 0:
                nsign = False
                nind = 0
            else:
                nsign = self.sign
                nind = self.ind
            nsign ^= exp // 2 != 0
            return Quat(nsign, nind)

    def __eq__(self, other):
        return other.sign == self.sign and other.ind == self.ind

    def __hash__(self):
        return self.ind + (8 if self.sign else 0)

    def __str__(self):
        return '%s%s'%('-' if self.sign else ' ', '1ijk'[self.ind])

    def __repr__(self):
        return str(self)

quats = {
    1: Quat(False, 0),
    -1: Quat(True, 0),
    'i': Quat(False, 1),
    'j': Quat(False, 2),
    'k': Quat(False, 3)
}

def search(arr, v1, v2, inOrder):
    l1, l2 = None, None
    for i, a in enumerate(arr):
        if l1 == None and v1 == a:
            l1 = i
        if v2 == a:
            l2 = i
    return l1 != None and l2 != None and (not inOrder or l1 < l2)

def test():
    L, X = map(int, input().split(' '))
    orig = [quats[x] for x in input()]
    xord = X % 4
    xpar = xord % 2
    if L * X < 3:
        return False
    psum = [Quat(False, 0)]
    for o in orig:
        psum.append(psum[-1] * o)
    e = psum[-1]

    s1vals = dict(( e ** (-a) * quats['i'] , a ) for a in range(3, -1, -1))
    s2vals = dict(( (quats['k'] * e ** (-(c+1))) ** -1, c ) for c in range(3, -1, -1))

    valid = []

    for s1, a in s1vals.items():
        for s2, c in s2vals.items():
            b = X - a - c - 1
            if b < 0:
                continue
            v3 = (s1 ** -1) * (e ** b) * s2

            if v3 == quats['j']:
                valid.append((s1, s2, b == 0))

    for v in valid:
        if search(psum, *v):
            return True

    return False

for case in range(1, int(input())+1):
    print('Case #%d: %s'%(case, 'YES' if test() else 'NO'))
