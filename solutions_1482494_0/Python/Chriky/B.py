import sys

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    N = int(f.readline())
    levels = [tuple(map(int, f.readline().split())) for level in range(N)]
    stars, goes = 0, 0
    levels.sort(key = lambda l: l[1])
    while levels:
        goes += 1
        
        if levels[0][1] <= stars:
            stars += 2
            levels.pop(0)
        else:
            possible = [l for l in levels if l[0] <= stars]
            if possible:
                stars += 1
                pick = possible[-1]
                levels.remove(pick)
                if pick[1] < 10**10:
                    levels += [(pick[1], 10**10)]
            else:
                goes = -1
                break
    print "Case #%d:" % (t + 1), goes if goes > 0 else "Too Bad"
