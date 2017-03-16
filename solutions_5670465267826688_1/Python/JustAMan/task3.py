import sys
import collections

MATRIX = '''
1  i  j  k
i -1  k -j
j -k -1  i
k j  -i -1
'''

MUL_MATRIX = {
}
for sym1, line in zip('1ijk', MATRIX.strip().splitlines()):
    MUL_MATRIX[sym1] = {}
    for sym2, res in zip('1ijk', line.strip().split()):
        neg = res.strip().startswith('-')
        MUL_MATRIX[sym1][sym2] = (res.strip().strip('-'), neg)

def multiply(symbols, value='1', positive=True):
    for sym in symbols:
        value, neg = MUL_MATRIX[value][sym]
        if neg:
            positive = not positive
        yield value, positive

Point = collections.namedtuple('Point', 'val sign')
def mulsign(data, start):
    value = start
    if not data:
        yield start
    for point in data:
        sym, neg = MUL_MATRIX[value.val][point.val]
        value = Point(val=sym, sign=value.sign * point.sign * (-1 if neg else 1))
        yield value

def power(value, positive, count):
    if count == 0:
        return '1', True
    for startVal, startPositive in multiply(value * count):
        pass
    startPositive = ((1 if startPositive else -1) * ((1 if positive else -1) ** count)) == 1
    return startVal, startPositive

def checkIjk(data):
    one, i, j, k = [Point(val=ch, sign=1) for ch in '1ijk']
    for idxI, value in enumerate(mulsign(data, start=one)):
        if value == i:
            break
    else:
        return False
    for value in mulsign(data[idxI + 1:], start=one):
        if value == j:
            break
    else:
        return False
    # we found i and j... what's left must be k
    return True

def checkSize(a1, a2, a3, size, repeat):
    length = a1 * size + a3 * size
    if a2 is None:
        length += size
    else:
        length += 2 * size + a2 * size
    return length <= size * repeat

def solve(symbols, repeat):
    #counts = {ch: symbols.count(ch) for ch in 'ijk'}
    #if counts.values().count(0) >= 2:
    #    return 'NO'

    for value, positive in multiply(symbols):
        pass

    if value == '1':
        if positive or repeat % 2 == 0:
            return 'NO'
    else:
        if repeat % 4 == 0 or repeat % 2 != 0:
            return 'NO'

    fills = [[list(mulsign([Point(val=value, sign=1 if positive else -1)] * count,
                           start=Point(val='1', sign=1)))[-1]] for count in (0, 1, 2, 3)]
    entry = [Point(val=sym, sign=1) for sym in symbols]

    for a1 in xrange(4):
        for a3 in xrange(4):
            if checkIjk(fills[a1] + entry + fills[a3]):
                if checkSize(a1, None, a3, len(symbols), repeat):
                    return 'YES'
            for a2 in xrange(4):
                if checkIjk(fills[a1] + entry + fills[a2] + entry + fills[a3]):
                    if checkSize(a1, a2, a3, len(symbols), repeat):
                        return 'YES'
    return 'NO'

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            L, X = [int(x) for x in inp.readline().strip().split()]
            symbols = inp.readline().strip()
            out.write('Case #%d: %s\n' % (t + 1, solve(symbols, X)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
