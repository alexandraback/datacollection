#!/usr/bin/python

import sys

def time_to_goal(start, per_second, goal):
    return (goal - start) / per_second

def solve_test_case(C, F, X):
    '''
    C - price for cookie farm,
    F - number of extra cookies per second for one farm,
    X - goal number of cookies
    '''
    per_second = 2.0
    total_time = 0.0
    while (time_to_goal(C, per_second, X) > time_to_goal(0, per_second + F, X)):
        total_time += time_to_goal(0, per_second, C)
        per_second += F
    total_time += time_to_goal(0, per_second, X)
    return total_time

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        C, F, X = (float(d) for d in f.readline().strip().split(' '))
        print 'Case #%d: %.7f' % (i, solve_test_case(C, F, X))

if __name__ == '__main__':
    main()
