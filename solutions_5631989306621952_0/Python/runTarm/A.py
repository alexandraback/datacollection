def solve(S):
    Q = ''
    for s in S:
        if Q and s >= Q[0]:
            Q = s + Q
        else:
            Q = Q + s

    return Q


import sys
sys.stdin = open('A-small-attempt0.in', 'rt')
sys.stdout = open('A-small.out', 'wt')

T = int(raw_input().strip())
for t in range(1, T+1):
    S = raw_input().strip()
    print 'Case #{}:'.format(t), solve(S)
