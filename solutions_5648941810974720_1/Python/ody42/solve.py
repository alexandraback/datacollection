import sys
from collections import defaultdict

NumberNames = [
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
]

class Counts(object):
    def __init__(self, S):
        
        self.counts = defaultdict(int)
        self.digit_counts = [0 for x in xrange(10)]
        
        if  S:
            for c in S:
                self.counts[c] = self.counts.get(c, 0) + 1
            return

        for c in counts:
            self.counts[c] = counts[c]




    # def without(self, i, n=1):
    #     'Return a copy of Counts without @n instances of i-th NumberName'

    #     name = NumberNames[i]
    #     ret = Counts(self.counts)

    #     self.digit_counts[i] += n

    #     for c in name:
    #         assert ret.counts[c] >= n
    #         ret.counts[c] -= n

    #     return ret

    def remove(self, i, n=1):
        'Remove @n instances of i-th NumberName'

        name = NumberNames[i]
        self.digit_counts[i] += n

        for c in name:
            assert self.counts[c] >= n
            self.counts[c] -= n

    def all_zero(self):
        for c in self.counts:
            #print '%s: %s' % (c, self.counts[c])
            assert self.counts[c] == 0

    def toString(self):
        ret = []
        ret.append('{')
        for c in sorted(self.counts):
            ret.append('  %s: %s,' % (c, self.counts[c]))
        ret.append('}')
        return '\n'.join(ret)

# A unique answer is guaranteed to exist.

def solve(S):
    counts = Counts(S)
    ans = []
    
    # E: 9 (ZERO, ONE, THREE, FIVE, SEVEN, EIGHT, NINE)
    # G: 1 (EIGHT)
    counts.remove(8, counts.counts['G'])
    # F: 2 (FOUR, FIVE)
    # I: 4 (FIVE, SIX, EIGHT, NINE)
    # H: 2 (THREE, EIGHT)
    # O: 4 (ZERO, ONE, TWO, FOUR)
    # N: 4 (ONE, SEVEN, NINE)
    # S: 2 (SIX, SEVEN)
    # R: 3 (ZERO, THREE, FOUR)
    # U: 1 (FOUR)
    counts.remove(4, counts.counts['U'])
    # T: 3 (TWO, THREE, EIGHT)
    # W: 1 (TWO)
    counts.remove(2, counts.counts['W'])
    # V: 2 (FIVE, SEVEN)
    # X: 1 (SIX)
    counts.remove(6, counts.counts['X'])
    # Z: 1 (ZERO)
    counts.remove(0, counts.counts['Z'])
    # Removed 0, 8, 2, 4, 6
    # E: 7 (ONE, THREE, FIVE, SEVEN, NINE)
    # F: 1 (FIVE)
    counts.remove(5, counts.counts['F'])
    # I: 2 (FIVE, NINE)
    # H: 1 (THREE)
    counts.remove(3, counts.counts['H'])
    # O: 1 (ONE)
    counts.remove(1, counts.counts['O'])
    # N: 4 (ONE, SEVEN, NINE)
    # S: 1 (SEVEN)
    counts.remove(7, counts.counts['S'])
    # R: 1 (THREE)
    counts.remove(3, counts.counts['R'])
    # T: 1 (THREE)
    counts.remove(3, counts.counts['T'])
    # V: 2 (FIVE, SEVEN)
    # Removed 1, 3, 5, 7
    # I: 1 (NINE)
    counts.remove(9, counts.counts['I'])
    # E: 1 (NINE)
    counts.remove(9, counts.counts['E'])
    # N: 2 (NINE)
    # Removed 9

    counts.all_zero()

    ret = []
    for i,count in enumerate(counts.digit_counts):
        ret.append(str(i) * count)

    return ''.join(ret)


def uniq_letters():
    cs = Counts(''.join(NumberNames))

    print cs.toString()

def uniq_letters_2(indexes):
    #indexes = [1, 3, 5, 7, 9]
    cs = Counts(''.join(NumberNames[i] for i in indexes))

    indexes = []
    
    for c in cs.counts:
        print ' %s: %s (%s)' % (c, cs.counts[c], ', '.join(NumberNames[i] for i in indexes if c in NumberNames[i]))

        if cs.counts[c] == 1:
            print "counts.remove(%s, counts.counts['%s'])" % (
                [i for i in indexes if c in NumberNames[i]][0],
                c
            )

def generate_code():
    indexes = set(range(10))

    while indexes:
        cs = Counts(''.join(NumberNames[i] for i in indexes))

        new_indexes = set(indexes)
        for c in cs.counts:
            print '# %s: %s (%s)' % (c, cs.counts[c], ', '.join(NumberNames[i] for i in indexes if c in NumberNames[i]))

            if cs.counts[c] == 1:
                ind = [i for i in indexes if c in NumberNames[i]][0]
                print "n = counts.counts['%s']" % c
                print "ans.extend([%s]*n)" % (ind, )
                print "counts.remove(%s, n)" % ind
                new_indexes.discard(ind)

        if indexes == new_indexes:
            print 'FAIL'
            return

        print '# Removed %s' % (', '.join(map(str, (indexes - new_indexes))))
        indexes = new_indexes

            
            
def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        S = sys.stdin.readline().strip()
        ans = solve(S)
        print 'Case #%s: %s' % (i+1, ans)

if __name__ == '__main__':
    main()
    #uniq_letters_2()

    #generate_code()
