from collections import deque
import re

class Rotator(object):

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def count(self):
        return sum(self.count_valid_recycle(n)
                   for n in range(self.a, self.b + 1))

    def count_valid_recycle(self, n):
        d = deque(str(n))
        s = set()
        for _ in range(len(d)):
            d.rotate()
            m = int(''.join(d))
            if n < m <= self.b:
                s.add((n, m))
        return len(s)

def process_input(string):
    for a, b in re.findall(r'^(\d+) (\d+)$', string, re.M):
        yield Rotator(int(a), int(b)).count()

#print len(filter(is_recycled, pairs(1, 1000)))
#print Rotator(1, 2000000).count()

if __name__ == '__main__':

    from sys import argv
    with open(argv[1]) as input, open(argv[1] + '.out', 'w') as out:
        result = process_input(input.read())
        cases = ('Case #%s: %s' % (i + 1, j) for (i, j) in enumerate(result))
        print >> out, '\n'.join(cases)
                                
        
