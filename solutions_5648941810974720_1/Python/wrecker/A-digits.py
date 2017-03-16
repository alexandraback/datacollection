from codejam import *

def read_file(f):
    s = read_string(f)
    return s

def solver(case):
    s = case
    counts = [0]*10
    for i, letter in enumerate('ZWXGTROFSE'):
        counts[i] = s.count(letter)
    ans = [0]*10
    ans[0] = counts[0]
    for i in (5, 6, 9):
        counts[i] -= counts[0]
    ans[2] = counts[1]
    for i in (4, 6):
        counts[i] -= counts[1]
    ans[6] = counts[2]
    for i in (8,):
        counts[i] -= counts[2]
    ans[8] = counts[3]
    for i in (9, 4):
        counts[i] -= counts[3]
    ans[3] = counts[4]
    for i in (5, 9, 9):
        counts[i] -= counts[4]
    ans[4] = counts[5]
    for i in (6, 7):
        counts[i] -= counts[5]
    ans[1] = counts[6]
    for i in (9,):
        counts[i] -= counts[6]
    ans[5] = counts[7]
    for i in (9, ):
        counts[i] -= counts[7]
    ans[7] = counts[8]
    for i in (9, 9):
        counts[i] -= counts[8]
    ans[9] = counts[9]
    output = []
    for digit, count in enumerate(ans):
        output.extend([str(digit)]*count)
    return ''.join(output)

solve('A-large', read_file, solver)
