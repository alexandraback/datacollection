import sys

input_fname = sys.argv[1]
input_f = open(input_fname)

output_fname = sys.argv[2]
output_f = open(output_fname, 'w')


def test_cases(input_f):
    return input_f.readline()


def parse_test_case(input_f):
    test_case = [['Y', 'Y', 'Y', 'Y'] for i in xrange(10)]
    for i in xrange(4):
        line = input_f.readline()
        chars = [c for c in line.strip()]
        test_case[i] = chars
        for j, c in enumerate(chars):
            test_case[j + 4][i] = c
            if i == j:
                test_case[8][i] = c
            if i + j == 3:
                test_case[9][j] = c
    input_f.readline()
    return test_case


X_WIN_SET = set(['T', 'X'])
O_WIN_SET = set(['T', 'O'])


def process_test_case(test_case):
    board_full = True
    X_win = False
    O_win = False
    for line in test_case:
        lineset = set(line)
        if '.' in lineset:
            board_full = False
        if len(lineset - X_WIN_SET) == 0:
            X_win = True
        if len(lineset - O_WIN_SET) == 0:
            O_win = True
    res = 'NO RES'
    if X_win and O_win:
        res = 'Draw'
    elif X_win:
        res = 'X won'
    elif O_win:
        res = 'O won'
    elif board_full:
        res = 'Draw'
    else:
        res = 'Game has not completed'
    return res


for icase in xrange(int(test_cases(input_f))):
    test_case = parse_test_case(input_f)
    # for line in test_case:
    #     print line
    res = process_test_case(test_case)
    output_f.write('Case #{0}: {1}\n'.format(icase + 1, res))


output_f.flush()
output_f.close()
