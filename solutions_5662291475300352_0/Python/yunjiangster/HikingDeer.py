import sys,re,math

def rl():
    return sys.stdin.readline().strip('\n')

def minEncounter(group):
    # assume fewer than 3 hikers
    hikers = []
    for D,H,M in group:
        for i in xrange(H):
            # starting, minutes, time to complete
            hikers.append((D,M+i, (360. - D) / (M+i) ))
    # answer should be 0 or 1
    if len(hikers) == 1: return 0
    elif len(hikers) == 2:
        h1, h2 = hikers
        if h2[:2] < h1[:2]:
            tmp = h1
            h1 = h2
            h2 = tmp
        #print h1, h2
        ct2 = (360 - h2[0] + 360) / h2[1]
        if ct2 > h1[2]: return 0
        else: return 1
    elif len(hikers) <= 10:
        pass 
            

T = int(rl())
for i in xrange(T):
    N = int(rl())
    group = []
    for j in xrange(N):
        group.append(map(int, rl().split()))
    print 'Case #%d: %d'%(i+1,minEncounter(group))
