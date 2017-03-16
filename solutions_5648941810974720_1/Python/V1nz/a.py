from sys import *
from math import *

def solve(case, tab) :
    # Zero
    solus = []
    while 'Z' in tab :
        solus.append(0)
        tab.remove('Z')
        tab.remove('E')
        tab.remove('R')
        tab.remove('O')
    # Two
    while 'W' in tab :
        solus.append(2)
        tab.remove('T')
        tab.remove('W')
        tab.remove('O')
    # Six
    while 'X' in tab :
        solus.append(6)
        tab.remove('S')
        tab.remove('I')
        tab.remove('X')
    # Seven
    while 'S' in tab :
        solus.append(7)
        tab.remove('S')
        tab.remove('E')
        tab.remove('V')
        tab.remove('E')
        tab.remove('N')
    # Eight
    while 'G' in tab :
        solus.append(8)
        tab.remove('E')
        tab.remove('I')
        tab.remove('G')
        tab.remove('H')
        tab.remove('T')
    # Eight
    while 'T' in tab :
        solus.append(3)
        tab.remove('T')
        tab.remove('H')
        tab.remove('R')
        tab.remove('E')
        tab.remove('E')
    # Four
    while 'U' in tab :
        solus.append(4)
        tab.remove('F')
        tab.remove('O')
        tab.remove('U')
        tab.remove('R')
    # Five
    while 'F' in tab :
        solus.append(5)
        tab.remove('F')
        tab.remove('I')
        tab.remove('V')
        tab.remove('E')
    # nine
    while 'I' in tab :
        solus.append(9)
        tab.remove('N')
        tab.remove('I')
        tab.remove('N')
        tab.remove('E')
    # one
    while 'O' in tab :
        solus.append(1)
        tab.remove('O')
        tab.remove('N')
        tab.remove('E')
    solus.sort()
    solution = ""
    for i in solus :
        solution = solution + str(i)
    print("Case #{0}: {1}".format(case, solution))

cases = int(input())
for i in range(1, cases + 1) :
    mot = input()
    tab = []
    for j in mot :
        tab.append(j)
    solve(i, tab)
