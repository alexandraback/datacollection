import sys

num_cases = int(sys.stdin.readline())

for case_num in range(num_cases):
    num_levels = int(sys.stdin.readline())
    levels = [(0,0)]*num_levels
    for level_num in range(num_levels):
        a, b = sys.stdin.readline().split()
        a, b = int(a), int(b)
        levels[level_num] = [b, a]
    levels.sort()
    stars = 0
    games = 0
    possible = True
    while len(levels) > 0 and possible:
        # Complete any levels that you can get two stars on
        i = 0
        while len(levels) > 0 and levels[0][0] <= stars:
            if levels[0][1] == -1:
                stars += 1
            else:
                stars += 2
            games += 1
            levels.pop(0)

        if len(levels) == 0:
            break

        # Complete the level with the highest 2-star requirement that we can complete
        possible = False
        for i in range(len(levels)-1,-1,-1):
            if levels[i][1] != -1 and levels[i][1] <= stars:
                possible = True
                stars += 1
                games += 1
                levels[i][1] = -1
                break
    if possible:
        result = games
    else:
        result = "Too Bad"
    print "Case #"+str(case_num+1)+":", result
