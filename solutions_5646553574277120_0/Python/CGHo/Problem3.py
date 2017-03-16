# -*- coding: utf-8 -*-  
DATA_FILE_NAME = 'C-small-attempt0.in'
# DATA_FILE_NAME = 'B-large-practice.in'
# DATA_FILE_NAME = 'test_data_b.dat'
#DATA_FILE_NAME = 'test3.in'
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


result_out = ''
import numpy as np


def solve(data_in):
    case_id, case_data = data_in
    c, d, v = map(int, case_data[0].split())
    coins = map(int, case_data[1].split())

    t2 = np.zeros(v + 1, dtype='b')
    t = {0}
    t3 = set(range(1,v + 1))
    for coin in coins:
        for i in range(0, c + 1):
            ad = i * coin
            temp_t = set()
            for j in t:
                temp_t.add(ad + j)
                t3 = t3 - {ad + j}
            for j in temp_t:
                t.add(j)
    #for i in t:
    #    t2[i] = 1
    #coins = {}
    a_coins = set()

    for i in range(1,v+1):
       if t3:
            if i not in coins:
                a_coins.add(i)
                for ii in range(0, c + 1):
                    ad = ii * i
                    temp_t = set()
                    for j in t:
                        temp_t.add(ad + j)
                        t3 = t3 - {ad + j}
                    for j in temp_t:
                        t.add(j)

    case_out = len(a_coins)

    return case_id, case_out


for idx, case_data in data_iterator(lines_to_read=2):
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

