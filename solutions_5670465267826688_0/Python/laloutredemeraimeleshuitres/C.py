import bisect

multable = {
    '1': { '1': '1', 'i': 'i',  'j': 'j',  'k': 'k' },
    'i': { '1': 'i', 'i': '-1', 'j': 'k',  'k': '-j' },
    'j': { '1': 'j', 'i': '-k', 'j': '-1', 'k': 'i' },
    'k': { '1': 'k', 'i': 'j',  'j': '-i', 'k': '-1' }
}

class Q:
    def __init__(self):
        self.sign = 1
        self.value = '1'
    def __mul__(self, x):
        t = multable[self.value][x]
        if t[0] == '-':
            self.sign = -self.sign
        self.value = t[-1]
        return self

    def __rmul__(self, x):
        t = multable[x][self.value]
        if t[0] == '-':
            self.sign = -self.sign
        self.value = t[-1]
        return self

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        s = '' if self.sign == 1 else '-'
        return s + self.value


def solve_case(L, S):
    S = L * S
    p = Q()
    stage = 0
    for c in S:
        if stage == 0 and str(p) == 'i':
            stage = 1
        if stage == 1 and str(p) == 'k':
            stage = 2
        p *= c
    if stage == 2 and str(p) == '-1':
        return 'YES'
    return 'NO'

def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        L, X = map(int, f.readline().split())
        print solve_case(X, f.readline().strip())

if __name__ == '__main__':
    import sys
    parse(sys.stdin)
