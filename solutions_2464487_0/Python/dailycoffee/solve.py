from math import pi
from fractions import Fraction

def solve(r, t):
    r = Fraction(r, 1)
    t = Fraction(t, 1)
    PI = Fraction(int(pi * 1e10), int(1e10))
    inner = pi * r * r
    circles = 0
    while True:
        r += 1
        black = PI * r * r - inner
        #print r, inner, black, black / PI, t
        t -= black / PI
        #print t
        if t < 0:
            break
        circles += 1
        r += 1
        inner = PI * r * r
    return circles

def line(f):
    return [int(n) for n in f.readline().rstrip().split()]

def main(f):
    for i in range(line(f)[0]):
        r, t = line(f)
        print('Case #{}: {}'.format(i + 1, solve(r, t)))

if __name__ == '__main__':
    import sys
    #with open('small.in') as f:
        #main(f)
    main(sys.stdin)
