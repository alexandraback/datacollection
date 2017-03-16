import sys

mul = { ('i', 'j'): ('k', False),
  ('i', 'k'): ('j', True),
  ('j', 'i'): ('k', True),
  ('j', 'k'): ('i', False),
  ('k', 'i'): ('j', False),
  ('k', 'j'): ('i', True) }

class Q:
    def __init__(self, n = '1', neg = False):
        self.neg = neg

        if n.startswith('-'):
            self.neg = True
        self.n = n.lstrip('-')

    def __str__(self):
        return ('-' if self.neg else '') + self.n

    def __repr__(self):
        return str(self)

    def __mul__(self, other):
        res = Q()
        res.neg = self.neg ^ other.neg

        if other.n == '1':
            res.n = self.n
        elif self.n == '1':
            res.n = other.n
        elif self.n == other.n:
            res.neg = not res.neg
            res.n = '1'
        else:
            res = Q(*mul[(self.n, other.n)])
            res.neg = res.neg ^ self.neg ^ other.neg

        return res

    def __neg__(self):
        return Q(self.n, not self.neg)

    def __eq__(self, other):
        return self.n == other.n and self.neg == other.neg

I   = Q('i')
J   = Q('j')
K   = Q('k')
One = Q('1')

def sol(s):
    qstr = list(map(lambda x: Q(x), s))
    prefix = []
    iind = []
    acc = One
    for i,x in enumerate(qstr):
        acc = acc * x
        if acc == I:
            iind.append(i)
        prefix.append(acc)

    acc = One
    kind = []
    suffix = []
    for i,x in enumerate(qstr[::-1]):
        acc = x * acc
        if acc == K:
            kind.append(len(s) - i - 1)
        suffix.append(acc)

    for i in iind:
        for k in filter(lambda x: x > i, kind):
            if -I * prefix[k - 1] == J:
                return 'YES'
    return 'NO'

tc = int(input())
for i in range(tc):
    x = int(input().split()[1])
    s = input()
    print('Case #%s:' % (i+1), sol(s * x))
