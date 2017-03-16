# -*- coding: utf-8 -*-
# python ProblemD.py < test4.in > D.small.out
# python ProblemD.py < D-small-attempt0.in > D.small.out
# =================================================================

def check(X, R, C):
    if X >= 7:
        return 'RICHARD'
    if R * C % X != 0:
        return 'RICHARD'
    if X > max(R, C):
        return 'RICHARD'
    if X <= 2:
        return 'GABRIEL'
    if X == 3:
        if min(R, C)>1:
            return 'GABRIEL'
        else:
            return 'RICHARD'
    if X == 4:
        if min(R, C) > 2:
            return 'GABRIEL'
        else:
            return 'RICHARD'

    if X == 5:
        if min(R, C) > 3:
            return 'GABRIEL'
        else:
            return 'RICHARD'

    if X == 6:
        if min(R, C) > 3:
            return 'GABRIEL'
        else:
            return 'RICHARD'

result_out = ''
case_num = int(raw_input())

for idx in range(case_num):
    X, R, C = map(int, raw_input().split())
    case_out = check(X, R, C)
    result_out += 'Case #%d: %s\n' % (idx+1, case_out)
print result_out
