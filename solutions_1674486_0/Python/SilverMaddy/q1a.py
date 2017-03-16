from collections import defaultdict
import itertools

def inherits(a, b):
    #print "i:", a, b
    #print d[a], b
    inh = 0
    if a in d[b]:
        inh += 1
    for i in d[b]:
        inherit = inherits(a,i)
        if inherit:
            inh += 1
    return inh

testcases = int(raw_input())
for t in xrange(1,testcases+1):
    n = int(raw_input())
    d = defaultdict(list)
    for i in xrange(1,n+1):
        classes = raw_input().split()
        d[i] = []
        for c in classes[1:]:
            d[i].append(int(c))
    ans = "No"
    for i in range(1,n+1):
        flag = 0
        for j in set(range(1,n+1)) - set([i]):
            ij = inherits(i, j)
            if ij >= 2:
                ans = "Yes"
                break
    print "Case #%d:" % t, ans
