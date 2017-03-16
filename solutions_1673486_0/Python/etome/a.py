

import sys

def prod(xs):
    res = 1.0
    for x in xs:
        res = res * x
    return res

T = int(sys.stdin.readline())

for i in range(1,T+1):
    line = sys.stdin.readline().split(' ')
    A = int(line[0])
    B = int(line[1])

    line = sys.stdin.readline().split(' ')
    p = map(float, line)

    exp = list()

    for k in range(0,A+1):
        pr = prod(p[0:A-k])
        exp.append( (1-pr)*(B-A+k+B+2+k) + \
                    pr*(B-A+k+1+k) )

    exp.append(B+2)

    print "Case #%d: %.8f" % (i, min(exp))




