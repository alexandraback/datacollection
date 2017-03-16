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
        if (r,c) in [(3,2),(3,3),(4,3)]:
            return "GABRIEL"
        else:
            return "RICHARD"
    if x == 4:
        if (r,c) in [(4,4),(4,3)]:
            return "GABRIEL"
        else:
            return "RICHARD"

def main():
    tc = int(line())
    for i in range(1,tc+1):
        x,r,c = ints(line())
        print 'Case #%s: %s' % (i, solve(x,r,c))

main()
