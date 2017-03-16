from sys import stdin
from pylab import floor, sqrt
from scipy.stats.distributions import binom

def parse():
    return tuple(int(x) for x in stdin.readline()[:-1].split(' '))

def solve(n, x, y):
    small  = int(floor((1 + sqrt(1 + 8 * n)) / 4))
    level  = ( abs(x) + abs(y) )/2 + 1
    left   = n - small*(2 * small - 1)
    height = y + 1
    if level <= small:
        return 1.0
    elif level > small + 1 or left < height or height > small*2:
        return 0.0
    elif left >= height + 2 * small:
        return 1.0
    else:
        return prob(height, left)

def prob(height, left):
    return 1 - binom(left, .5).cdf(height - 1)

if __name__ == '__main__':
    T = int(stdin.readline())
    for i in xrange(T):
        print 'Case #' + str(i + 1) + ':', solve(*parse())
