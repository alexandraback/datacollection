#!/usr/bin/python
inf = open('in', 'r')

strings = inf.read().split("\n")
n = int(strings[0])
position = 1
for i in range(1,n+1):
    n_levels = int(strings[position])
    position += 1
    levels = []
    for j in range(1, n_levels+1):
        levels.append([int(a) for a in strings[position].split(" ")])
        position += 1
    sorted_levels = sorted(levels, key=lambda data: data[1]*2002 + data[0], reverse=True)
    result = 0
    progress = True
    stars = 0
    while progress:
        progress = False
        new_levels = sorted_levels
        beat_2_stars = True
        while beat_2_stars:
            beat_2_stars = False
            for level in reversed(sorted_levels):
                if level[1] > stars:
                    break
                progress = True
                beat_2_stars = True
                result += 1
                if (level[0] == 'x'):
                    stars += 1
                else:
                    stars += 2
                new_levels.pop()
            sorted_levels = new_levels
        for level in sorted_levels:
            if level[0] != 'x' and level[0] <= stars:
                progress = True
                stars += 1
                result += 1
                level[0] = 'x'
                break;
    if len(sorted_levels):
        print "Case #%d: Too Bad" % i
    else:
        print "Case #%d: %d" % (i, result)
    i += 1

inf.close()
