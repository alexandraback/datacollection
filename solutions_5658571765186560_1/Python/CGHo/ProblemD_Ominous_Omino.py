# -*- coding: utf-8 -*-  
__author__ = 'DR&QM'
#DATA_FILE_NAME = 'D-small-attempt0.in'
DATA_FILE_NAME = 'D-large.in'
# DATA_FILE_NAME = 'test_data_b.dat'
# DATA_FILE_NAME = 'test4.in'
SHELL_PIPE_FLAG = False
# =================================================================
def data_iterator(lines_to_read=None):
    if not SHELL_PIPE_FLAG:
        with open(DATA_FILE_NAME, 'r') as f_handle:
            line_iter = f_handle.xreadlines()
            case_no = int(line_iter.next())
            for idx in range(case_no):
                if not lines_to_read:
                    line_no = int(line_iter.next())
                    yield idx + 1, [line_iter.next().strip() for _ in range(line_no)]
                else:
                    yield idx + 1, [line_iter.next().strip() for _ in range(lines_to_read)]
    else:
        import sys  # raw_input() sys.stdin.readline()
        case_no = int(sys.stdin.readline())
        for idx in range(case_no):
            if not lines_to_read:
                line_no = int(sys.stdin.readline())
                yield idx + 1, [sys.stdin.readline().strip() for _ in range(line_no)]
            else:
                yield idx + 1, [sys.stdin.readline().strip() for _ in range(lines_to_read)]

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
import heapq, math
def solve(data_in):
    case_id, case_data = data_in
    X, R, C = map(int, case_data[0].split())
    case_out = check(X, R, C)
    return case_id, case_out


for idx, case_data in data_iterator(lines_to_read=1):
    (_, case_out) = solve((idx, case_data))
    # print case_data
    # print '========================'
    result_out += 'Case #%d: %s\n' % (idx, case_out)
print result_out

if not SHELL_PIPE_FLAG:
    import os

    if not os.path.exists('Out'):
        os.makedirs('Out')

    with open('./Out/' + DATA_FILE_NAME + '.out', 'wb') as f:
        f.write(result_out)

#with open(DATA_FILE_NAME+'.out','wb') as f:
#    f.write(result_out)
