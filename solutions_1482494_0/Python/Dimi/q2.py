f = open("B-small-attempt2.in", "r")
T = int(f.readline())
for X in range(T):
    N = int(f.readline())
    d = {}
    A = []
    B = []
    for n in range(N):
        line = f.readline().strip().split()
        a=int(line.pop(0))
        b=int(line.pop(0))
        d[n+1]=[a,b]
    complete = False
    Y = 0
    stars = 0
    bad = False
    fast = True
    i=1
    n=N
    new_stars = False
    while d!={} and not bad:
        if i not in d:
            i += 1
        elif fast:
            if d[i][1] <= stars:
                Y += 1
                stars += 2
                del d[i]
                i+=1
                new_stars = True
            else:
                i += 1
            if i > len(d):
                if not new_stars:
                    fast = False
                new_stars = False
                i = 1
        else:
            if d[i][1] <= stars:
                stars += 2
                del d[i]
                Y += 1
                i+=1
                new_stars = True
            elif d[i][1] == (stars + 1) and d[i][0] <= stars and d[i][0] != '!':
                Y += 2
                stars += 3
                del d[i]
                i+=1
                new_stars = True
            elif d[i][0] <= stars:
                d[i][0] = '!'
                Y += 1
                stars += 1
                i+=1
                new_stars = True
            else:
                i += 1
            if new_stars:
                fast = True
                i = 1
            elif i > len(d):
                bad = True
                    
    if bad:
        print "Case #%d: Too Bad" % (X+1)
    else:
        print "Case #%d: %d" % (X+1, Y)