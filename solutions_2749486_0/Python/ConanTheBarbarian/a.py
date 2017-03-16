from __future__ import print_function
import unittest
import sys

sin = '''4
3 4
-3 4
3 -4
-3 -4'''

def err(*msgs, **argv):
    print(*msgs, file=sys.stderr, **argv)



class State(object):

    def __init__(self, x, y, X, Y):
        self.x = x
        self.y = y
        self.X = X
        self.Y = Y
        self.path = ''


def solveCase(X, Y):
    EW = True if X < 0 else False
    NS = True if Y < 0 else False
    X, Y = abs(X), abs(Y)
    x, y = 0, 0
    i = 1
    result = ''
    while 1:
        if x <= X - i:
            x += i
            result += 'E'
        elif y <= Y - i:
            y += i
            result += 'N'
        elif x < X:
            x += 1
            result += 'WE'
        elif y < Y:
            y += 1
            result += 'SN'
        else:
            break
        i += 1

    if EW:
        result = result.replace('E', 'X').replace('W', 'E').replace('X', 'W')
    if NS:
        result = result.replace('N', 'X').replace('S', 'N').replace('X', 'S')
    return result


def solveAll(s):
    it = iter(s.split('\n'))
    T = int(it.next())
    for i in range(T):
        X, Y = map(int, it.next().split(' '))
        yield('Case #%s: %s' % (i + 1, solveCase(X, Y)))

def test():
    print('\n'.join(solveAll(sin)))

if __name__ == '__main__':
    if 'test' in sys.argv[1:]:
        test()
        sys.exit(0)
    print('\n'.join(solveAll(open('B-small-attempt0.in').read())))
