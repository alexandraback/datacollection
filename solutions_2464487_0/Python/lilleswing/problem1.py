__author__ = 'karl'
import string
import math


def get_rings(r, t):
    a = 2
    b = 2*r - 1
    c = -1 * t
    desc = (math.sqrt(b*b - 4 * a * c)/(2*a))
    rings = int((-b + math.sqrt(b*b- 4*a*c))/(2*a))
    if int(desc) == desc:
        return rings - 1
    return rings

if __name__ == '__main__':
    data = map(string.strip, open('A-small-attempt0.in').readlines())
    rounds = int(data[0])
    for round in xrange(1,rounds+1):
        r , t = map(lambda x: int(x), data[round].split(' '))
        rings = get_rings(r,t)
        print "Case #%d: %d" % (round, rings)
