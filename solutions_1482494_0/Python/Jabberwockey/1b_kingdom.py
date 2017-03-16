#!/usr/bin/python
'''
Created on 28.04.2012

@author: Jens Grabarske
'''

import sys

def goal_p(lst):
    return len(lst) == len(filter(lambda x: x == 2, lst))


# The idea is to first try to greedily consume all the 2-star versions of the levels
# as possible. If no more versions can be found, find the 1-star version that hasn't
# been played yet and has the lowest 2-star threshold (allowing us to continue the
# quest for more 2-star achievements). If there is no such 1-star version, it's too bad.
def solution(matrix):
    no_games = 0
    no_stars = 0
    win_list = [0 for x in range(len(matrix))]
    failure  = False
    while not (failure or goal_p(win_list)):
        change = False
        for i in range(len(matrix)):
            if (matrix[i][1] <= no_stars) and (win_list[i] < 2):
                change = True
                no_games += 1
                no_stars += (2 - win_list[i])
                win_list[i] = 2
                
        if not change:
            highest = 0
            index  = len(matrix) + 1
            for i in range(len(matrix)):
                if (matrix[i][0] <= no_stars) and (win_list[i] == 0):
                    if matrix[i][1] > highest:
                        highest = matrix[i][1]
                        index  = i
                         
            if index > len(matrix):
                failure = True
            else:
                no_games += 1
                no_stars += 1
                win_list[i] = 1
                
    if failure:
        return "Too Bad"
    else:
        return no_games


def treat_case(no):
    no_levels = int(sys.stdin.readline())
    matrix    = [map(int,sys.stdin.readline().split(" ")) for x in range(no_levels)]
    print "Case #" + str(no) + ":", solution(matrix)


if __name__ == '__main__':
    number = int(sys.stdin.readline())
    for i in range(1,number + 1):
        treat_case(i)
