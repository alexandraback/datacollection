#!/usr/bin/python2.7

from math import ceil

f = open('input.txt', 'r')
T = int(f.readline())

def calc_moves(p_arr, thres):
    moves = 0
    for p in p_arr:
        moves += int(ceil(float(p) / thres)) - 1
    return moves

def solve(p_arr):
    D = len(p_arr)
    best_total = max(p_arr)
    for thres in range(1, best_total):
        moves = calc_moves(p_arr, thres)
        if thres + moves < best_total:
            best_total = thres + moves
    print best_total

for t in range(T):
    D = int(f.readline().rstrip())
    p_arr = map(int, f.readline().rstrip().split(' '))
    assert D == len(p_arr)

    print "Case #" + str(t + 1) + ":",
    solve(p_arr)
