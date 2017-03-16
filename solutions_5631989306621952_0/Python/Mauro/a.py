from toolz import *

def read_int():
    return int(raw_input())

def solve(s):
    ret = s[0]
    for i in s[1:]:
        if i >= ret[0]:
            ret = i + ret
        else:
            ret = ret + i
    return ret
            
for case in range(read_int()):
    S = raw_input()
    ans = solve(S)
    print "Case #%d: %s" % (case+1, ans)
