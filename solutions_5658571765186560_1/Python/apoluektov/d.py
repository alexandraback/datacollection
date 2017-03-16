import sys

def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]


def solve(x,r,c):
    r,c = max(r,c), min(r,c)
    if x == 1:
        return "GABRIEL"
    if x == 2:
        if r*c % 2 == 0:
            return "GABRIEL"
        else:
            return "RICHARD"
    if x == 3:
        if c >= 2 and r >= 3 and r*c % 3 == 0:
            return "GABRIEL"
        else:
            return "RICHARD"
    if x == 4:
        if c >= 3 and r >= 4 and r*c % 4 == 0:
            return "GABRIEL"
        else:
            return "RICHARD"

    if x == 5:
        if c >= 4 and r >= 5 and r*c % 5 == 0:
            return "GABRIEL"
        else:
            return "RICHARD"

    if x == 6:
        if c >= 4 and r >= 6 and r*c % 6 == 0:
            return "GABRIEL"
        else:
            return "RICHARD"


    return "RICHARD"


def main():
    tc = int(line())
    for i in range(1,tc+1):
        x,r,c = ints(line())
        print 'Case #%s: %s' % (i, solve(x,r,c))

main()
