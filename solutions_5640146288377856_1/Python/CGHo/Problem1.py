# -*- coding: utf-8 -*-  
DATA_FILE_NAME = 'A-small-attempt1.in'
DATA_FILE_NAME = 'A-large.in'
# DATA_FILE_NAME = 'test_data_b.dat'
#DATA_FILE_NAME = 'test1.in'
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

def solve(data_in):
    case_id, case_data = data_in
    r, c, w = map(int, case_data[0].split())

    y = 0
    while c >2*w-1:
        y += r
        c = c - w
    if r > 1:
        y = y + r - 1
    if c>w:
        y = y +1
    y = y + w
    case_out = y
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

