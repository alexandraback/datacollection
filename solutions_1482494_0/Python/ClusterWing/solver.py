import sys
import math

T = int(sys.stdin.readline())

for case in range(1, T + 1) :
    output = "Case #" + str(case) + ": "
    line = sys.stdin.readline().strip().split(" ")
    N = int(line[0])
    level = []
    for _ in range(N):
        line = sys.stdin.readline().strip().split(" ")
        level.append([int(e) for e in line])

    def sorter(a, b):
        if len(a) != len(b):
            return len(a) - len(b)
        else:
            if (a < b):
                return -1
            if (a > b):
                return 1
            return 0

    level.sort(cmp=sorter)

    currentStar = 0;
    result = 0
    while len(level) > 0:
        result += 1
        # print level
        _ = level.pop(0)
        if len(_) == 2:
            if _[1] <= currentStar :
                currentStar += 2
                level.sort(cmp=sorter)
            elif _[0] <= currentStar:
                currentStar += 1
                level.append([_[1]])
                level.sort(cmp=sorter)
            else:
                result = None
                break
        else:
            if _[0] <= currentStar:
                currentStar += 1
            else:
                if (all([len(e) == 1 for e in level])):
                    result = None
                    break
                else:
                    level.append(_)
                    result -= 1
    if result is None:
        output  += "Too Bad"
    else:
        output += str(result)
    print output

