import sys

def done(stars_needed):
    for level in stars_needed:
        if level[1] is not None: return False
    return True

def level_cmp(level_a, level_b):
    if level_a[1] == level_b[1]:
        return level_a[0]-level_b[0]
    else:
        return level_a[1]-level_b[1]

def test(stars_needed):
    stars = 0
    played = 0
    stars_needed.sort(cmp=level_cmp,reverse=True)
    #print >>sys.stderr,stars_needed
    while not done(stars_needed):
        #print >>sys.stderr, 'have', stars, 'stars, played', played
        found = False
        for i,level in enumerate(stars_needed):
            if level[1] is not None and level[1] <= stars:
                #print >>sys.stderr, 'played %d-%d' % (i+1,2)
                played += 1
                stars += 1
                if level[0] is not None: stars += 1
                stars_needed[i][1] = None
                found = True
        if found: continue
        #print >>sys.stderr, 'no 2 star avail'
        for i,level in enumerate(stars_needed):
            if level[0] is not None and level[1] is not None and level[0] <= stars:
                #print >>sys.stderr, 'playing %d-%d' % (i+1,1)
                played += 1
                stars += 1
                stars_needed[i][0] = None
                break
        else:
            return "Too Bad"
    return played
                    
            
    
    
        
    
    

T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    stars_needed = [map(int, raw_input().split()) for n in xrange(N)]
    print >>sys.stderr, t
    print "Case #%d:" % (t+1), test(stars_needed)
