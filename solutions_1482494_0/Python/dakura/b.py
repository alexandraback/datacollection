#! /usr/bin/env python
# -*- coding:utf-8 -*-
import sys

sys.setrecursionlimit(1100)
#sys.maxint
#-sys.maxint-1

def cleanup(star, rs, starlevel, cleared):
    for i in range(len(star[rs])-1, -1, -1):
        level = star[rs][i]
        if cleared[starlevel][level] == 1:
            del star[rs][i]
    if len(star[rs]) == 0:
        del star[rs]

def solveit(N, levels):
    star1 = {}
    star2 = {}
    for i in range(N):
        if levels[i][0] not in star1:
            star1[levels[i][0]] = [i]
        else:
            star1[levels[i][0]].append(i)
        if levels[i][1] not in star2:
            star2[levels[i][1]] = [i]
        else:
            star2[levels[i][1]].append(i)

    cleared = [[0]*N, [0]*N]
    answer = 0
    star = 0
    while True:
        if len(star2) == 0:
            break
        rs = min(star2)
        if rs <= star:
            reserve_best = -1
            reserve = -1
            min1 = 0
            for j in range(len(star2[rs])):
                level = star2[rs][j]
                if cleared[1][level] == 1:
                    continue
                if cleared[0][level] == 0:
                    if levels[level][0] >= min1:
                        reserve_best = level
                        min1 = levels[level][0]
                else:
                    reserve = level

            if reserve_best >= 0:
                star += 2
                cleared[1][reserve_best] = 1
                cleanup(star2, rs, 1, cleared)
                answer += 1
                continue
            if reserve >= 0:
                star += 1
                cleared[1][reserve] = 1
                cleanup(star2, rs, 1, cleared)
                answer += 1
                continue

        if len(star1) == 0:
            return "Too Bad"

        rs = min(star1)
        if rs <= star:
            reserve = -1
            min2 = 0
            for j in range(len(star1[rs])):
                level = star1[rs][j]
                if cleared[0][level] == 0 and cleared[1][level] == 0:
                    if levels[level][1] >= min2:
                        reserve = level
                        min2 = levels[level][1]
                    break
            if reserve >= 0:
                # clear it !
                star += 1
                cleared[0][reserve] = 1
                cleanup(star1, rs, 0, cleared)
                answer += 1
                continue
        return "Too Bad"

    return str(answer)

if __name__ == '__main__':
    f = open(sys.argv[1])

    num_of_case = int(f.readline())
    for i in range(num_of_case):
        N = int(f.readline())
        levels = []
        for j in range(N):
            levels.append(map(int, f.readline().rstrip().split()))
        answer = solveit(N, levels)
        print "Case #%d: %s" % (i+1, answer)

# sort by key
# for k,v in sorted(d.items())
# sort by value
# for k,v in sorted(d.items(), key=lambda x:x[1])
# items() return tapple, tapple[0] is k, tapple[1] is v
#
# import copy
# copy.copy()
# copy.deepcopy()
#
# a = [0]*100
#

