from itertools import combinations
from itertools import permutations
from itertools import product 
import re
def occurrenes(text, sub):
    return len(re.findall('(?={0})'.format(re.escape(sub)), text))
alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
t = input()
for _ in xrange(1,t+1):
    k,l,s = map(int, raw_input().split())
    key = raw_input()
    tar = raw_input()
    prob = {}
    key_list = list(set(list(key)))
    #print key_list
    combi = list([''.join(p) for p in product(key_list, repeat=s)])
    ans = 0
    maxx = 0
    for a in alp:
        prob[a] = float(key.count(a))/k
    for i in combi:
        occ = occurrenes(i,tar)
        maxx = max(maxx, occ)
        cal = occ * reduce(lambda x,y: x*y, [prob[cc] for cc in i])
        ans += cal
    #print prob
    #print maxx - ans
    print "Case #%d: %f" % (_, maxx-ans)
