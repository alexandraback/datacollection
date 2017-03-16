from operator import itemgetter
from itertools import chain

T = int(raw_input())

for t in xrange(T):
    n = int(raw_input())
    naomi = map(float, raw_input().split())
    ken = map(float, raw_input().split())
    
    bricks = [1 if brick < n else -1 for brick in zip(*sorted(enumerate(chain(naomi, ken)), key=itemgetter(1)))[0]]
    
    fair = 0    
    for brick in bricks:
        fair = max(0, fair + brick)
    
    cheat = 0
    for brick in bricks:
        cheat = max(0, cheat - brick)
    
    print "Case #{}: {} {}".format(t + 1, n - cheat, fair)