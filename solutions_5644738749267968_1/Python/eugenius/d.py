"""
Author: Eugene Yurtsev
"""
import sys

STDIN = sys.stdin
num_cases = int(STDIN.readline())

def parse_case():
    num_blocks = int(STDIN.readline())
    N = map(float, STDIN.readline().split(' '))
    K = map(float, STDIN.readline().split(' '))
    N.sort()
    K.sort()
    w1 = [('U', w) for w in N]
    w2 = [('D', w) for w in K]
    w1.extend(w2)
    w1.sort(key = lambda x : x[1])
    w1 = [w[0] for w in w1]
    return w1

def solve_war(seq):
    num = len(seq)
    for i in range(num):
        if seq[i] == 'U':
            for j in range(i+1, num):
                if seq[j] == 'D':
                    seq[i] = '.'
                    seq[j] = '.'
                    break
    seq = [s for s in seq if s <> '.']
    return len(seq)/2

def solve_deceipt(seq):
    num = len(seq)
    naomi = 0
    for i in range(num-1, 0, -1):
        if seq[i] == 'U':
            for j in range(i, -1, -1):
                if seq[j] == 'D':
                    seq[i] = '.'
                    seq[j] = '.'
                    naomi += 1
                    break
        elif seq[i] == 'D':
            for j in range(0, i):
                if seq[j] == 'U':
                    seq[i] = '.'
                    seq[j] = '.'
                    break
    return naomi


for case in range(num_cases):
    seq = parse_case()
    score_1 = solve_deceipt(list(seq)) # Copy to its not affected for score_2
    score_2 = solve_war(seq) # Don't create copy for speed
    print 'Case #{}: {} {}'.format(case+1, score_1, score_2)
