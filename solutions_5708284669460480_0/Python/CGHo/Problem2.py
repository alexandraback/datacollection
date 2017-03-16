# -*- coding: utf-8 -*-  
DATA_FILE_NAME = 'B-small-attempt3.in'
# DATA_FILE_NAME = 'B-large-practice.in'
# DATA_FILE_NAME = 'test_data_b.dat'
#DATA_FILE_NAME = 'test2.in'
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
from collections import Counter
def solve(data_in):
    case_id, case_data = data_in
    k, l, s = map(int, case_data[0].split())
    K = case_data[1]
    K_list = list(K)
    L = case_data[2]
    L_list = list(L)
    c = Counter(K)

    for i in list(L):
        if i not in K_list:
            return case_id, 0.0
    over_count = 0
    for i in range(len(L_list)/2):
        if L_list[i] == L_list[-i-1]:
            over_count += 1

    over_count = 0
    for i in range(len(L)/2):
        #print L_list[i] , L_list[-i-1]
        if L[:i]==L[-i:]:
            over_count = i
    step = l - over_count
    if step == 0:
        step = 1
    y_max = 0
    ss = s
    while ss>=l:
        y_max += 1
        ss -= step

    p = 1
    for j in L_list:
        p = p * c[j]
    p = p *1.0 / k**l
    #y_avg = y_max - 1.0* s / l * p
    y_avg = y_max - y_max * p
    #if y_avg <0:
    #    y_avg = 0
    case_out = y_avg
    return case_id, case_out


for idx, case_data in data_iterator(lines_to_read=3):
    (_, case_out) = solve((idx, case_data))
    # print case_data
    # print '========================'
    result_out += 'Case #%d: %.9f\n' % (idx, case_out)
print result_out

if not SHELL_PIPE_FLAG:
    import os

    if not os.path.exists('Out'):
        os.makedirs('Out')

    with open('./Out/' + DATA_FILE_NAME + '.out', 'wb') as f:
        f.write(result_out)

