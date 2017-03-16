from toolz import *

def read_int():
    return int(raw_input())

def solve(pairs):
    distinct1 = len(set([i for i, j in pairs]))
    distinct2 = len(set([j for i, j in pairs]))
    maxim = max(distinct1, distinct2)
    return len(pairs) - maxim
            
for case in range(read_int()):
    inp = []
    for i in range(read_int()):
        inp.append(raw_input().split())
    ans = solve(inp)
    print "Case #%d: %s" % (case+1, ans)
