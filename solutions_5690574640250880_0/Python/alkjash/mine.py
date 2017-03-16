#! /usr/bin/env python

import sys

try:
    fin = open(sys.argv[1], "r")
except:
    sys.exit("Error: input file")

fout = open("mineout.txt", "w")

T = int(fin.readline())

def print_grid(r, c, m):
    while r > 0:
        if r > 3:
            if m >= c:
                fout.write('*' * c + "\n")
                m -= c
                r -= 1
            elif m <= (c - 2) or m == 0:
                fout.write('*' * m + '.' * (c-m) + "\n")
                m = 0
                r -= 1
            else: # m == c - 1
                fout.write('*' * (c-2) + '.' * 2 + "\n")
                m -= c - 2
                r -= 1
        elif r == 3:
            assert (m < 3 * c)
            if m <= c - 2 or m == 0:
                fout.write('*' * m + '.' * (c-m) + "\n")
                m = 0
                r -= 1
            elif (r * c - m) % 2 == 0 or (r * c - m) == 1:
                fout.write('*' * c + "\n")
                m -= c
                r -= 1
            else:
                fout.write('*' * (c - 3) + '.' * 3 + "\n")
                m -= c - 3
                r -= 1
        elif r == 2:
            assert (m < 2 * c)
            assert (m == 2 * c - 1 or m % 2 == 0)
            if m == 2 * c - 1:
                fout.write('*' * c + "\n")
                m -= c
                r -= 1
            else: 
                fout.write('*' * (m/2) + '.' * (c - (m/2)) + "\n")
                m /= 2
                r -= 1
        else: # r == 1
            assert (m <= c-1)
            fout.write('*' * m + '.' * (c - m - 1) + 'c' + "\n")
            r -= 1
    return 0        

for i in range(T):
    fout.write("Case #" + str(i+1) + ":\n")
    arr = map(int, fin.readline().split(' '))
    s = arr[0] * arr[1] - arr[2]

    if arr[0] == 1 or arr[1] == 1:
        print_grid(arr[0], arr[1], arr[2])
    elif arr[0] == 2 or arr[1] == 2:
        if s == 1 or ((s % 2) == 0 and s >= 4):
            print_grid(arr[0], arr[1], arr[2])
        else:
            fout.write("Impossible\n")
    else:
        if (s in [1,4,6,8]) or s >= 9:
            print_grid(arr[0], arr[1], arr[2])
        else:
            fout.write("Impossible\n")
