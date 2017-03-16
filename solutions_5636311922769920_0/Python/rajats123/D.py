def we1(size=None):
    text=raw_input()
    we12=text.split(' ')
    if size is not None:assert len(we12)==size
    return we12
def we123(count,func):
    for x in xrange(0,count):
        func(x)
def we1234(we12345, fmt, *args):
    we123456 = 'Case #{}:'.format(we12345 + 1)
    if len(args):print we123456, fmt % args
    else:print we123456, fmt
        
class we1234567(object):
    def __init__(self, qw1, qw12):
        self.qw1 = qw1
        self.qw12 = qw12

    @property
    def volume(self):
        return self.qw1 ** self.qw12

    def qw123(self, index):
        assert 0 <= index < self.volume
        qw1234 = []
        for eq1 in range(0, self.qw12):
            m = index / (self.qw1 ** eq1)
            qw1234.append(m % self.qw1)
        assert len(qw1234) == self.qw12
        return qw1234

    def index_from_qw1234(self, qw1234):
        assert len(qw1234) == self.qw12
        index = 0
        for eq1, factor in enumerate(qw1234):
            index += factor * (self.qw1 ** eq1)
        return index

    def eq12(self):
        eq123 = list(range(0, self.qw1)) 
        eq12346 = []
        while eq123:
            qw1234 = eq123[:self.qw12] 
            del eq123[:self.qw12]
            if len(qw1234) < self.qw12:
                qw1234 += [0] * self.qw12
                qw1234 = qw1234[:self.qw12]
            index = self.index_from_qw1234(qw1234)
            eq12346.append(index)
        eq12346.sort()
        assert self.eq1234(eq12346)
        return eq12346

    def eq1234(self, eq12346):
        qw1234s = [self.qw123(i) for i in eq12346]
        qw1234 = reduce(lambda a, b: a+b, qw1234s, [])
        return set(range(0, self.qw1))==set(qw1234)

def eq123467(x):
    return map(lambda e:e+1,x)

def eq1234678(x):
    return map(lambda e:e-1,x)
def solution(we12345):
    K,C,S=map(int, we1())
    qw1=K
    qw12=C
    rq1=S

    f=we1234567(qw1, qw12)
    eq12346 = eq123467(f.eq12())
    if len(eq12346) > rq1:
        we1234(we12345, 'IMPOSSIBLE')
    else:
        we1234(we12345,' '.join(map(str, eq12346)))

if __name__=='__main__':
    count=input()
    we123(count,solution)
