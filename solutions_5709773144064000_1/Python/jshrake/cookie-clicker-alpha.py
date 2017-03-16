import sys


def cookie_income(F, P):
    return 2 + F * P


def time_to_win(current, goal, farms, farm_income):
    return (goal - current) / (2 + farms * farm_income)


def solution(X, F, C):
    t = 0.0
    farms = 0
    while True:
        # time to win from 0 to X with no additional farms
        zero_to_goal = time_to_win(0, X, farms, F)
        # time to get from 0 to C with current number of farms
        zero_to_c = time_to_win(0, C, farms, F)
        # time to win from 0 to X with one additional farm
        zero_to_goal_2 = time_to_win(0, X, farms + 1, F)
        if zero_to_goal < zero_to_c + zero_to_goal_2:
            return t + zero_to_goal
        else:
            farms += 1
            t += zero_to_c


num_cases = int(sys.stdin.readline())
for case in range(1, num_cases + 1):
    C, F, X = map(float, sys.stdin.readline().split())
    print("Case #" + str(case) + ": %.7f" % solution(X, F, C))
