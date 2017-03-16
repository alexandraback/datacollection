t = input()

def encounter(hikers):
    # upper bounded by 2
    # deer follows directly behind first hiker
    # stay behind hiker, wait for one ahead to cross 0,
    # then go
    # if hiker catchs up then just go
    if hikers[0][0] < hikers[1][0]:
        earlier = hikers[0]
        later = hikers[1]
    else:
        earlier = hikers[1]
        later = hikers[0]
    t = (360 - later[0] + earlier[0]) * later[2] / 360.0
    if t > (360 - earlier[0]) * earlier[2] / 360.0:
        return 1
    return 0


for i in xrange(1, t+1):
    n = input()
    hiks = [ map(int, raw_input().split()) for _ in xrange(n) ]
    if n == 1:
        if hiks[0][1] == 2:
            hiks.append( list(hiks[0]) )
            hiks[0][1] = 1
            hiks[1][1] = 1
            hiks[1][2] = hiks[0][2] + 1
    if len(hiks) == 1:
        print 'Case #%d: 0' % i
    else:
        print 'Case #%d: %d'% (i, encounter(hiks))

