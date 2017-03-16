import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next


def solve(s):
    arr = [i for i in s]
    out = 0
    while True:
        while arr and arr[-1] == '+':
            arr = arr[:-1]
        if not arr:
            return out
        if arr[0] == '+':
            out += 1
            for i in xrange(len(arr)):
                if arr[i] == '+':
                    arr[i] = '-'
                else:
                    break
        arr = arr[::-1]
        out += 1
        for i in xrange(len(arr)):
            if arr[i] == '+':
                arr[i] = '-'
            else:
                arr[i] = '+'
    return out

T = int(cin())
for cn in xrange(1,T+1):
    s = cin()
    print "Case #%d: %s" % (cn, str(solve(s)))


