import sys

T = int(sys.stdin.readline())

for i in range(T):
    N = int(sys.stdin.readline())
    levels = []
    for j in range(N):
        line = sys.stdin.readline()
        line = line.split()
        a = int(line[0])
        b = int(line[1])
        levels.append((a,b))
    half_levels = []
    levels = sorted(levels, key = lambda x: x[1])
    stars = 0
    steps = 0
    remov = True
    levels.reverse()
    while (remov):
        levels.reverse()
        remov = False
        removed = True
        while (removed):
           removed = False
           for l in half_levels:
                if (stars >= l):
                    stars = stars + 1
                    steps = steps + 1
                    half_levels.remove(l)
                    removed = True
           for l in levels:
                if (stars >= l[1]):
                    steps = steps + 1
                    stars = stars + 2
                    levels.remove(l)
                    removed = True
        levels.reverse()
        for l in levels:
            if (stars >= l[0]):
                steps = steps + 1
                stars = stars + 1
                half_levels.append(l[1])
                levels.remove(l)
                half_levels = sorted(half_levels)
                remov = True
                break
    if (levels == [] and half_levels == []):
        print("Case #%s: %d" % (str(i+1),steps))
    else:
        print("Case #%s: Too Bad" % str(i+1))
