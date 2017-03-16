def count_them(a, b):
    count = 0
    for n in xrange(a, b+1):
        strn = str(n)
        h = {}
        for i in xrange(len(strn)):
            m = int(strn[i:] + strn[:i])
            if m in h:
                continue
            h[m] = True
            if m > n and m <= b:
                count += 1
    return count

import sys
lines = sys.stdin.read().split("\n")[1:-1]
case_count = 0
for line in lines:
    case_count += 1
    a, b = map(int, line.split())
    print "Case #%i: %i" % (case_count, count_them(a, b))
