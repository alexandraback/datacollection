
from math import floor, sqrt

def solve(r, t):
    b = 2*r-1
    i = int(floor((sqrt(b*b+8*t)-b)/4.0))
    while 2*i*i + b*i > t:
        i=i-1
    return i

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        r, t = [int(j) for j in f.readline().strip().split()]
        print "Case #{0}: {1}".format(i+1, solve(r, t))

if __name__ == '__main__':
    with open('A-small-attempt0.in') as f:
        main(f)