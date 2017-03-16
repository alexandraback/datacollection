__author__ = 'gingva'

import sys,operator,time



def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:
            t = time.time()
            ncases = int(f.next().strip())
            for n in range(ncases):
                L,X = [int(c) for c in f.next().strip('\r\n').split()]
                s = f.next().strip('\r\n')
                assert(len(s) == L)
                print 'Case #%d %d %d'  % (n + 1, L, X )
                b = solve(s, X)
                print >> g, 'Case #%d: %s' % (n + 1, b)
                sys.stdout.flush()
                print time.time()-t, 'sec', b

class Quat:
    header = '1ijk'
    table = [['1', 'i', 'j', 'k'],
             ['i', '-1', 'k', '-j'],
             ['j', '-k', '-1', 'i'],
             ['k', 'j', '-i', '-1']]
    times = {h: {} for h in header}
    for i, h in enumerate(header):
        for j, h2 in enumerate(header):
            r = table[i][j]
            times[h][h2] = r

    def __init__(self, letter, s=1):
        if len(letter) == 1:
            self.letter = letter
            self.sign = s
        elif len(letter) == 2:
            self.letter = letter[1]
            self.sign = -s
            assert (letter[0] == '-')
        else:
            raise ValueError('letter has to be len 1 or 2')

    def __mul__(self, other):
        return Quat(self.times[self.letter][other.letter], self.sign * other.sign)

    def __str__(self):
        s = '-' * (self.sign < 0)
        s += self.letter
        return s

    def matches(self,l):
        return self.letter == l and self.sign == 1

    def __eq__(self, other):
        return self.letter == other.letter and self.sign == other.sign

    
    

class RepeatedStr:
    def __init__(self,s,X,prefix='',suffix = '',quat = None):
        self.s = s
        self.X = X
    def __len__(self):
        return self.X * len(self.s)

    def iterFull(self):
        'only use if going through the full sequence as the middle part is compressed'
        for x in range(self.X % 4):
            for c in self.s:
                yield c

    def iterLeftRight(self):
        for x in range(min(self.X, 4)):
            for c in self.s:
                yield c

    def scanLeftRight(self):
        q = Quat('1')
        for i,c in enumerate(self.iterLeftRight()):
            q = q * Quat(c)
            if q.matches('i'):
                return i


    def iterRightLeft(self):
        for x in range(min(self.X, 4)):
            for c in reversed(self.s):
                yield c


    def scanRightLeft(self):
        q = Quat('1')
        for (i,c) in enumerate(self.iterRightLeft()):
            q = Quat(c) * q
            if q.matches('k'):
                return len(self)-1-i

def reduceCharSeq(s):
    q = Quat('1')
    for c in s:
        q = q * Quat(c)
    return str(q)

ijk = reduceCharSeq('ijk')

def solve(s, X):
    full = RepeatedStr(s, X)
    if reduceCharSeq(full.iterFull()) <> ijk:
        return 'NO'
    minI = full.scanLeftRight()
    if minI is None:
        return 'NO'
    maxK = full.scanRightLeft()
    if maxK is None:
        return 'NO'
    if minI < maxK:
        return 'YES'
    return 'NO'




if __name__ == '__main__':
    #main('C-test.in', 'C-test.out')
    main('C-small-attempt1.in', 'C-small-attempt1.out')
    #main('C-large.in', 'C-large.out')


