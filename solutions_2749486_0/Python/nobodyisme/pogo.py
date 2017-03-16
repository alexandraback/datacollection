import math
import sys

input_fname = sys.argv[1]
input_f = open(input_fname)

output_fname = sys.argv[2]
output_f = open(output_fname, 'w')


VOWELS = 'aeiou'

def test_cases(input_f):
    return input_f.readline()


def parse_test_case(input_f):
    _x, _y = [int(x) for x in input_f.readline().split(' ')]
    return (_x, _y)


X_DIR = 'WE'
Y_DIR = 'SN'



def process_test_case(test_case):
    _x, _y = test_case

    path = ''
    step = 1
    cur_x, cur_y = 0, 0


    if abs(_x) < abs(_y):
        FIRST_DIR, SECOND_DIR = Y_DIR, X_DIR
        first_coord, second_coord = _x, _y
    else:
        FIRST_DIR, SECOND_DIR = X_DIR, Y_DIR
        first_coord, second_coord = _y, _x

    pos_dir = True

    # special cases:
    if _x == 1 and _y == 1:
        return 'ENNS'
    elif _x == 1 and _y == -1:
        return 'ESSN'
    elif _x == -1 and _y == 1:
        return 'WNNS'
    elif _x == -1 and _y == -1:
        return 'WSSN'


    while (cur_x != _x or cur_y != _y) and not step > 300:

        if step == abs(first_coord):
            if first_coord < 0:
                idx = 0
            else:
                idx = 1
            if FIRST_DIR == Y_DIR:
                path += X_DIR[idx]
                cur_x = _x
            else:
                path += Y_DIR[idx]
                cur_y = _y

        else:
            idx = 1 if pos_dir else 0
            if FIRST_DIR == Y_DIR:
                path += Y_DIR[idx]
                if pos_dir:
                    cur_y += step
                else:
                    cur_y -= step
            else:
                path += X_DIR[idx]
                if pos_dir:
                    cur_x += step
                else:
                    cur_x -= step
            pos_dir = not pos_dir

        # print path[-1]
        # print cur_x, cur_y

        step += 1

    if step > 201:
        raise ValueError

    return path



for icase in xrange(int(test_cases(input_f))):
    test_case = parse_test_case(input_f)
    # for line in test_case:
    #     print line
    print "Processing test case", icase + 1
    res = process_test_case(test_case)
    output_f.write('Case #{0}: {1}\n'.format(icase + 1, res))


output_f.flush()
output_f.close()
