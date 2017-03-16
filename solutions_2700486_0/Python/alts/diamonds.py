import math
import sys

def stack(l, n, g):
    s = [0 for _ in xrange(l)]

    for i in xrange(g):
        s[i] = 1.0

    rev = range(l - 1, -2, -1)


    for g in xrange(n):
        p = 0.5
        for i in rev:
            if i == -1:
                v = 1
            else:
                v = s[i]

            if i == l-1:
                overflow = p*v
                p -= overflow
            else:
                x = p*v
                s[i+1] += x
                p -= x

    return s

def remaining(diamonds, pd):
    return diamonds - (pd * (2 * pd - 1))

def pyramidality(diamonds):
    return int((math.sqrt(1 + 8*diamonds) + 1) / 4)

def solve(diamonds, x, y):
    pd = pyramidality(diamonds)
    pdf = pd * 2 - 1
    md = abs(x) + y
    if md <= pdf:
        return 1.0

    rem = remaining(diamonds, pd)

    if rem == 0:
        return 0.0

    pdf2 = (pd + 1) * 2 - 1
    if md > pdf2:
        return 0.0

    guaranteed = 0
    if rem > pd*2:
        guaranteed = rem - pd*2

    s = stack(pd*2, rem - 2 * guaranteed, guaranteed)

    if y == 0:
        return s[0]
    elif md % 1:
        return s[y-1]
    else:
        try:
            return s[y]
        except IndexError:
            return 0.0

    return None

def main(input):
    lines = map(lambda x: map(int, x.split()), input.strip().split('\n'))
    num_cases, = lines.pop(0)
    for i in xrange(num_cases):
        diamonds, x, y = lines.pop(0)
        print 'Case #{0}: {1}'.format(i+1, solve(diamonds, x, y))

main(sys.stdin.read())