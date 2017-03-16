from fractions import Fraction
#ugly casework

file = open('C-small.in')

T = int(file.readline().strip())

for case in xrange(1,T+1):
    N = int(file.readline().strip())
    hikers = []
    for hiker_group in xrange(N):
        group = file.readline().strip()
        D,H,M = (int(s) for s in group.split(' '))
        for i in xrange(H):
            hikers.append((D,M+i))
    
    if len(hikers)<2:
        answer = 0
    elif len(hikers) > 2:
        answer = -1
    else:
        hikers.sort()
        near_hiker = hikers[0]
        far_hiker = hikers[1]
        if near_hiker[1] == far_hiker[1]:
            answer = 0
        else:
            if near_hiker[1] > far_hiker[1]:
                # near_hiker is slower
                near_hiker,far_hiker = far_hiker,near_hiker
            
            near_hiker_cross_line_twice = near_hiker[1]*(2-near_hiker[0]/Fraction(360,1))
            far_hiker_cross_line_once = far_hiker[1]*(1-far_hiker[0]/Fraction(360,1))
            if near_hiker_cross_line_twice <= far_hiker_cross_line_once:
                answer = 1
            else:
                answer = 0
        
        
        
    print "Case #%d: %d" % (case,answer)