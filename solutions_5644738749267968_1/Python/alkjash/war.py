#! /usr/bin/env python

import sys

try:
    fin = open(sys.argv[1], "r")
except:
    sys.exit("Error: filename.")

fout = open("warout.txt", "w")

T = int(fin.readline())

def solve_war(a, b):
    ans = 0
    m = len(a) - 1
    n = len(b) - 1
    while m >= 0 and n >= 0:
        if a[m] > b[n]:
            ans += 1
            m -= 1
        else:
            m -= 1
            n -= 1
    return ans

for i in range(T):
    fout.write("Case #" + str(i+1) + ": ")
    fin.readline()
    a = sorted(map(float, fin.readline().split(' ')))
    b = sorted(map(float, fin.readline().split(' ')))
    fout.write(str(len(a) - solve_war(b, a)) + ' ' + str(solve_war(a, b)) + "\n")
