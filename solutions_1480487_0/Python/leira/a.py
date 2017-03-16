#!/usr/bin/env python

def inp(fin):
    return [eval(x) for x in fin.readline().strip().split()]

def safevote(ave, s, j):
    if ave <= j:
        return 0.0
    else:
        return (ave - j)/s*100

def solveCase(fin):
    ln = inp(fin)
    n = ln[0]
    J = ln[1:]
    s = sum(J)
    av1 = 2*(s + 0.0)/len(J)
    Js = [j for j in J if j < av1]
    av = (sum(Js) + s + 0.0)/len(Js)
    safe = []
    for j in J:
        safe.append(safevote(av, s, j))
    return " ".join(["%f" % s for s in safe])

def solve(fin):
    [ncase] = inp(fin)
    for i in xrange(ncase):
        print "Case #%d: %s" % (i+1, solveCase(fin))

def main():
    import sys
    solve(sys.stdin)

if __name__ == "__main__":
    main()

