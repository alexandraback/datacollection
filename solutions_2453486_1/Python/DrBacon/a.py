#!/usr/bin/python

import os
import sys

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []

for i in range(T):
    case = []
    for j in range(4):
        case.append([k for k in fh.readline().strip()])
    dummy = fh.readline().strip()
    cases.append(case)

fh.close()


d_X={"X":"X", "O":".", ".":".", "T":"X"}
d_O={"X":".", "O":"O", ".":".", "T":"O"}

def determine_win(case):
    for r in range(4):
        if map(lambda z: d_X[z], case[r]) == ['X', 'X', 'X', 'X']:
            return "X won"
        elif map(lambda z: d_O[z], case[r]) == ['O', 'O', 'O', 'O']:
            return "O won"
    for c in range(4):
        if map(lambda z: d_X[z], map(lambda j: case[j][c], range(4))) == ['X', 'X', 'X', 'X']:
            return "X won"
        elif map(lambda z: d_O[z], map(lambda j: case[j][c], range(4))) == ['O', 'O', 'O', 'O']:
            return "O won"
    if map(lambda z: d_X[z], map(lambda j: case[j][j], range(4))) == ['X', 'X', 'X', 'X']:
        return "X won"
    if map(lambda z: d_O[z], map(lambda j: case[j][j], range(4))) == ['O', 'O', 'O', 'O']:
        return "O won"
    if map(lambda z: d_X[z], map(lambda j: case[j][3-j], range(4))) == ['X', 'X', 'X', 'X']:
        return "X won"
    if map(lambda z: d_O[z], map(lambda j: case[j][3-j], range(4))) == ['O', 'O', 'O', 'O']:
        return "O won"
    if "." not in sum(case, []):
        return "Draw"
    return "Game has not completed"

            

fh_o = open("out.txt","w")
for i, case in enumerate(cases):
    
    print >> fh_o, "Case #"+str(i+1)+": "+ determine_win(case)

fh_o.close()

