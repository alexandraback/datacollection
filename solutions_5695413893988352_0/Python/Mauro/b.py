from toolz import *

def read_int():
    return int(raw_input())

def good(qm, score):
    for i, j in zip(qm, score):
        if i != '?' and i != j:
            return False
    return True

def solve(inp):
    x, y = inp
    best = (1234, 1234)
    best_diff = 1234
    ma = 10 ** len(x)
    for i in range(0, ma):
        if good(x, str(i).zfill(len(x))):
            for j in range(0, ma):
                if good(y, str(j).zfill(len(x))):
                    if abs(i - j) < best_diff:
                        best = (i, j)
                        best_diff = abs(i - j)
    return best
            
for case in range(read_int()):
    inp = raw_input().split()
    ans = solve(inp)
    length = len(inp[0])
    print "Case #%d: %s %s" % (case+1, str(ans[0]).zfill(length), str(ans[1]).zfill(length))
