# -*- coding: utf-8 -*-  
__author__ = 'DR&QM'
DATA_FILE_NAME = 'C-small-attempt0.in'
# DATA_FILE_NAME = 'C-large.in'
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
cross_table = {('1','1'):'1', ('1','i'):'i', ('1','j'):'j', ('1','k'):'k',
               ('i','1'):'i', ('i','i'):'-1', ('i','j'):'k', ('i','k'):'-j',
               ('j','1'):'j', ('j','i'):'-k', ('j','j'):'-1', ('j','k'):'i',
               ('k','1'):'k', ('k','i'):'j', ('k','j'):'-i', ('k','k'):'-1',}
def cross(x, y):
    sign = '-' if (('-' in x) ^ ('-' in y)) else ''
    return (sign + cross_table[(x.replace('-', ''), y.replace('-', ''))]).replace('--','')

def search_i_j(repeat_time, X, L, L_tot, L1, first_i):

    idx_j = -1
    if not (first_i == None):
        # search_for = ['j']
        idx_j = first_i + 1
    else:
        first_i = 0
        # search_for = ['i','j']
        current = '1'
        for idx in xrange(first_i, len(L) * repeat_time+1):
            current = cross(current, L[idx % len(L)])
            if current == 'i':
                idx_j = idx + 1
                break
    if idx_j < 0:
        return 'NO'
    current = '1'
    for idx in xrange(idx_j, len(L) * repeat_time+1):
        current = cross(current, L[idx % len(L)])
        if current == 'j':
            return 'YES'
    return 'NO'







def check_L(X, L, L_tot, L1, first_i):

    if L_tot == '1':
        return 'NO'
    if L_tot == '-1':
        if X % 2 == 0:
            return 'NO'
        repeat_time = min (X, 5)
        return search_i_j(repeat_time, X, L, L_tot, L1, first_i)

    if X % 2 == 0:
        if X % 4 == 0:
            return 'NO'
        repeat_time = min (X, 9)
        return search_i_j(repeat_time, X, L, L_tot, L1, first_i)
    else:
        return 'NO'



def solve(data_in):
    case_id, case_data = data_in
    _, X = map(int, case_data[0].split())
    L = list(case_data[1])
    L1 = list(case_data[1])
    first_i = 0 if L[0] == 'i' else None
    for i in range(1, len(L1)):
        L1[i] = cross(L1[i-1], L1[i])
        if first_i is None and L1[i] == 'i':
            first_i = i
    L_tot = L1[-1]


    case_out = check_L(X, L, L_tot, L1, first_i)
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

#with open(DATA_FILE_NAME+'.out','wb') as f:
#    f.write(result_out)
