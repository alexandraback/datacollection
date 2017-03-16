from sys import stdin
from pylab import fromstring, ceil, log2

def parse():
    init, n = tuple(int(x) for x in stdin.readline()[:-1].split(' '))
    motes   = fromstring(stdin.readline()[:-1], sep=' ', dtype=int)
    return init, motes, n

def solve(init, motes, n):
    motes.sort()
    size  = init
    adds  = 0
    minop = n
    for i in xrange(motes.size):
        add, size = numAdd(size, motes[i])
        adds += add
        minop = min(minop, adds + n - i - 1)
    return minop

def numAdd(init, nex):
    if init < 2:
        return float('inf'), init
    add = max(int(ceil(log2(float(nex)/(init - 1)))), 0)
    size = 2**add * (init - 1) + 1 + nex
    return add, size

if __name__ == '__main__':
    T = int(stdin.readline())
    for i in xrange(T):
        print 'Case #' + str(i + 1) + ':', solve(*parse())
