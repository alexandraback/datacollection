#! /usr/bin/python

import os, sys

T = int(sys.stdin.readline())

# For each test case
for t in range(1, T+1):
    line = sys.stdin.readline().split(' ')
    N = int(line[0])
    M = int(line[1])
    list_n = []
    for i in range(0, N):
        list_m = []
        for j in range(0, M):
            list_m.append(int(sys.stdin.read(1)))
            sys.stdin.read(1)
        list_n.append(list_m)
    #sys.stdin.read(1)
    greatest_rows = [max(x) for x in list_n]
    greatest_columns = []

    for i in range(0,M):
        column = [row[i] for row in list_n]
        greatest_columns.append(max(column))

    found_error = False
    for i in range(0,N):
        if found_error: break
        for j in range(0,M):
            if list_n[i][j] not in [greatest_rows[i], 
                                    greatest_columns[j]]:
                found_error = True
                break

    if found_error:
        sys.stdout.write('Case #%s: NO\n' % t)
    else:
        sys.stdout.write('Case #%s: YES\n' % t)
