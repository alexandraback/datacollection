from itertools import *

for t in range(1, int(input())+1):
    j, p, s, k = map(int, raw_input().split())
    
    ans = 1
    combs = []
    count = [{} for i in range(3)]
    for a,b,c in product(range(1, j+1), range(1, p+1), range(1, s+1)):
        fail = False
        for i,pair in enumerate([(a,b), (b,c), (a,c)]):
            if pair in count[i]:
                if count[i][pair] == k:
                    fail = True
                else:
                    count[i][pair] += 1
            else:
                count[i][pair] = 1
        if fail:
            continue
        combs += ['%d %d %d' % (a,b,c)]
        ans += 1
    
    print "Case #%d: %d" % (t, ans-1)
    print '\n'.join(combs)