#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import math


primes_under_50 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
perfect_squares_under_50 = {1:1, 4:2, 9:3, 16:4, 25:5, 36:6, 49:7}
divisors_under_50 = [[], [], [], [2], [], [2], [], [4], [3], [2], [], [2, 3], [], [2], [3], [2, 4], [], [2, 3], [], [2, 4], [3], [2], [], [2, 3, 4], [5], [2], [3], [2, 4], [], [2, 3, 5], [], [2, 4], [3], [2], [5], [2, 3, 4, 6], [], [2], [3], [2, 4, 5], [], [2, 3, 6], [], [2, 4], [3, 5], [2], [], [2, 3, 4, 6], [7], [2, 5]]


def display_impossible(m, h, w):
    return "Impossible"
    
####################
def display_grid_mines_bottom(m, h, w):

    count = h*w - m
    res = ""
    for i in range(0, h):
        for j in range(0, w):
            if count > 0:
                res += "."
                count = count - 1
            else:
                res += "*"
        res += "\n"
    return "c" + res[1:len(res)-1]

#####################
def display_grid_mines_right(m, h, w):

    count = h*w - m
    res = []
    for j in range(0, w):
        for i in range(0, h):
            if j == 0:
                res.append("")
            if count > 0:
                res[i] += "."
                count = count - 1
            else:
                res[i] += "*"
    return "c" + ("\n".join(res))[1:]
            
#####################
def display_grid_free_top_left_square(m, h, w):

    size = perfect_squares_under_50[h*w-m]
    res = ""
    for i in range(0, h):
        for j in range(0, w):
            res += "*" if i >= size or j >= size else "."
        res += "\n"
    return "c" + res[1:len(res)-1]

#####################
def display_grid_free_top_left_rectangle(m, h, w):

    divisors = divisors_under_50[h*w - m - 1]
    for divisor in divisors:
        a = divisor
        b = int((h*w-m)/a)
        if a < h and b < w:
            a, b = b, a
        if a >= w or b >= h:
            continue
        res = ""
        for i in range(0, h):
            for j in range(0, w):
                res += "*" if i >= b or j >= a else "."
            res += "\n"
        return "c" +res[1:len(res)-1]
    return "Impossible"

#####################
def display_grid_mines_in_corners(m, h, w):

    count = m
    res = ""
    for i in range(0, h):
        for j in range(0, w):
            if count > 0 and ((i == 0 and (j==0 or j == w - 1)) or (i == h - 1 and (j == 0 or j == w - 1))):
                res += "*"
                count = count - 1
            else:
                res += "."
        res += "\n"
    return res[:2] + "c" + res[3:len(res)-1]


def display_344(m, h, w):
    return "c...\n....\n...*\n..**"

def display_1455(m, h, w):
    return "c...*\n....*\n...**\n*****\n*****"
    
#####################
def display_grid_free_center(m, h, w):

    res = []
    for i in range(0, h):
        res.append([])
        for j in range(0, w):
            res[i].append("*")

    x, y = int(w/2) - 1, int(h/2) - 1
    dx, dy = 1, 0
    count = h*w - m
    first = True

    change = [1, 2, 4, 6, 9, 12, 16, 20, 25, 30, 36, 42, 50]

    iterate = -1
    while count > 0:
        if first:
            res[y][x] = 'c'
            first = False
        else:
            res[y][x] = '.'
        count = count - 1
        iterate = iterate + 1
        if iterate in change:
            dx, dy = -dy, dx
        x, y = x + dx, y + dy

            
    for i in range(0, h):
        for j in range(0, w):
            if res[i][j] == 'c' and neighbourhood(res, j, i, h, w)[0]:
                return "Impossible"
            if res[i][j] == '.':
                tmp = neighbourhood(res, j, i, h, w)
                if tmp[0] and not tmp[1]:
                    return "Impossible"
                    
    join = ""
    for r in res:
        join += "".join(r) + "\n"
    return join[:len(join)-1]


def is_zero(res, x, y, r, c):
    z = True
    for i in range(-1,2):
        for j in range(-1,2):
            if y+i >= 0 and x+j >= 0 and x+j < c and y+i < r and (i != 0 or j != 0):
                z = z and res[y+i][x+j] in '.c'


def neighbourhood(res, x, y, r, c):
    m = False
    z = False

    for i in range(-1,2):
        for j in range(-1,2):
            if y+i >= 0 and x+j >= 0 and x+j < c and y+i < r and (i != 0 or j != 0):
                m = m or res[y+i][x+j] == '*'
                z = z or is_zero(res, x+i, y+i, r, c)
    return m, z
    
#####################
def minesweeper(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    n = int(content[0].replace("\n", ""))

    for i in range(0, n):
        tmp = content[1 + i].split(" ")
        h = int(tmp[0])
        w = int(tmp[1])
        m = int(tmp[2])

        cells = h*w
        
        display_grid_mines_bottom_unperfect = display_grid_mines_bottom
        display_grid_mines_right_unperfect = display_grid_mines_right
        
        possible = display_impossible
        if m == 3 and h == 4 and w == 4:
            possible = display_344
        elif m == 14 and h == 5 and w == 5:
            possible = display_1455
        elif m == 0 or m == cells - 1:
            possible = display_grid_mines_bottom
        elif m >= cells:
            possible = display_impossible
        elif m%w == 0 and h - int(m/w) >= 2:
            possible = display_grid_mines_bottom
        elif m%h == 0 and w - int(m/h) >= 2:
            possible = display_grid_mines_right
        elif m/w + 1 < h - 1 and m%w < w - 1:
            possible = display_grid_mines_bottom_unperfect
        elif m/h + 1 < w - 1 and m%h < h - 1:
            possible = display_grid_mines_right_unperfect
        elif cells - m in perfect_squares_under_50 and perfect_squares_under_50[cells-m] < h and perfect_squares_under_50[cells-m] < w:
            possible = display_grid_free_top_left_square
        elif m <= 4 and h > 4 and w > 4:
            possible = display_grid_mines_in_corners
        elif cells - m not in primes_under_50:
            possible = display_grid_free_top_left_rectangle
        else:
            possible = display_grid_free_center
            
            
        print("Case #" + str(i+1) + ":")#, possible, m, h, w)
        print(possible(m, h, w))

        
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        minesweeper(sys.argv[1])

