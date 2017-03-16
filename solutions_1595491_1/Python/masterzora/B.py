# B.py

import sys
import os

expected_map = {0: [0], 1: [1], 2: [1], 3: [1], 4: [2], 5: [2], 6: [2], 7: [3], 8: [3], 9: [3], 10: [4], 11: [4], 12: [4], 13: [5], 14: [5], 15: [5], 16: [6], 17: [6], 18: [6], 19: [7], 20: [7], 21: [7], 22: [8], 23: [8], 24: [8], 25: [9], 26: [9], 27: [9], 28: [10], 29: [10], 30: [10]}
surprising_map = {0: [], 1: [], 2: [2], 3: [2], 4: [2], 5: [3], 6: [3], 7: [3], 8: [4], 9: [4], 10: [4], 11: [5], 12: [5], 13: [5], 14: [6], 15: [6], 16: [6], 17: [7], 18: [7], 19: [7], 20: [8], 21: [8], 22: [8], 23: [9], 24: [9], 25: [9], 26: [10], 27: [10], 28: [10], 29: [], 30: []}

def main():
    s = ' '.join(sys.stdin.readlines()).split()
    os.close(0)

    T = int(s[0])
    s = s[1:]
    for i in range(T):
        N = int(s[0])
        S = int(s[1])
        p = int(s[2])
        t = []
        t_marks = []
        for j in range(N):
            t += [int(s[2 + j + 1])]
            t_marks += [mark(int(s[2 + j + 1]), p)]

        selections = mark_surprising(t_marks, S)
        winners = filter(lambda X: X[0] == 'SW' and X[2] == True or X[0] == 'EW' and X[2] == False or X[0] == 'BW', selections)
        print 'Case #%s: %s' % (i+1, len(winners))
        
        s = s[3 + N:]

def mark_surprising(marks, S):
    num_selected = 0
    for i in marks:
        if num_selected == S:
            break
        if i[0] == 'SW':
            i[2] = True
            num_selected += 1
    for i in marks:
        if num_selected == S:
            break
        if i[0] == 'BW':
            i[2] = True
            num_selected += 1
    for i in marks:
        if num_selected == S:
            break
        if i[0] == 'N':
            i[2] = True
            num_selected += 1
    for i in marks:
        if num_selected == S:
            break
        if i[0] == 'EW' and not i[1]:
            i[2] = True
            num_selected += 1
    return marks

def mark(num, p):
    exp_max = expected_map[num][0]
    sup_max = surprising_map[num]
    if len(sup_max) == 0:
        return ['E' if exp_max < p else 'EW', True, False]
    sup_max = sup_max[0]
    if exp_max >= p and sup_max >= p:
        return ['N' if exp_max < p else 'BW', False, False]
    elif sup_max >= p and exp_max < p:
        return ['SW', False, False]
    else:
        return ['N' if exp_max < p else 'EW', False, False]
        

if __name__ == "__main__":
    main()
