from __future__ import division

import sys

def solve(J):
    X = sum(J)
    J = [float(j)/X for j in J]
    Js = list(sorted(J))
    T = 2.0 / len(J)

    while Js[-1] >= T:
        Js.pop()
        T = (sum(Js) + 1.0) / len(Js)

    res = []
    for j in J:
        if j >= T:
            res.append(0)
        else:
            res.append(100*(T-j))
    return res

if __name__ == '__main__':
    NP = int(sys.stdin.readline())
    for i in xrange(NP):
        L = map(int, sys.stdin.readline().split())
        print("Case #%d: %s" % (i+1, " ".join(map(str, solve(L[1:])))))
