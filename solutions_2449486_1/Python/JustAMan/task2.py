'''
Problem B. Lawnmower
Solution by vassnlit@gmail.com
'''

LAWN = [
    [2, 2, 2, 2, 2],
    [2, 1, 1, 1, 2],
    [2, 1, 2, 1, 2],
    [2, 1, 1, 1, 2],
    [2, 2, 2, 2, 2],
]

class LawnData:
    def __init__(self, lawn):
        self._lawn = lawn
        self._columnCache = {}

    def getRow(self, y):
        return self._lawn[y]

    def getColumn(self, x):
        try:
            return self._columnCache[x]
        except KeyError:
            column = [row[x] for row in self._lawn]
            self._columnCache[x] = column
            return column

    def canCutPoint(self, x, y):
        column, row = self.getColumn(x), self.getRow(y)
        value = row[x]
        return (value == max(row)) or (value == max(column))

def solve(lawn, N, M):
    lawnData = LawnData(lawn)
    for y in xrange(N):
        for x in xrange(M):
            if not lawnData.canCutPoint(x, y):
                return 'NO'
    return 'YES'

import sys
with open(sys.argv[1], 'r') as inp:
    T = int(inp.readline().strip())
    for t in xrange(T):
        N, M = [int(x) for x in inp.readline().strip().split()]
        lawn = []
        for n in xrange(N):
            lawn.append([int(x) for x in inp.readline().strip().split()])
        print 'Case #%d: %s' % (t+1, solve(lawn, N, M))
