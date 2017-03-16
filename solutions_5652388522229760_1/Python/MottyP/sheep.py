import sys

ALL_DIGITS = set('0123456789')

def solveCase(N):
    seen = set()
    curr = N
    while True:
        seen |= set(str(curr))
        if seen == ALL_DIGITS:
            return curr
        curr += N

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        N = int(inp.readline())
        if N == 0:
            print "Case #%d: INSOMNIA" % cs
        else:
            lastnum = solveCase(N)
            print "Case #%d: %d" % (cs, lastnum)

if __name__ == '__main__':
    _doMain()

