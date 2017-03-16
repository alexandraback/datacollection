import sys
def test(N,S,p,ti):
    if p >= 2:
        min_unsurprise = p+(p-1)+(p-1)
    elif p == 1:
        min_unsurprise = 1
    else:
        min_unsurprise = 0
    print >>sys.stderr, 'min_unsurprise', min_unsurprise

    if p >= 4:
        min_surprise = p+(p-2)+(p-2)
    elif p == 3:
        min_surprise = 3+1+1
    elif p == 2:
        min_surprise = 2
    elif p == 1:
        min_surprise = 1
    else:
        min_surprise = 0
    print >>sys.stderr, 'min_surprise', min_surprise
    ti.sort()

    easy = 0
    surprise = 0
    for i in ti:
        if i >= min_unsurprise: easy += 1
        elif i >= min_surprise: surprise += 1

    return str(easy+min(surprise,S))
        
    
    

T = int(raw_input())
for t in xrange(T):
    line = raw_input().split()
    N, S, p = map(int, line[:3])
    ti = map(int, line[3:])
    print >>sys.stderr, t
    print "Case #%d:" % (t+1), test(N,S,p,ti)
