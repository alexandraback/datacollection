import copy
import sys

################################################################################
import collections, operator

import math

flag = False

def solve(case_inputs):
    B, M =  case_inputs

    res = [[0] * B for i in range(B)]
    biggest = int(math.log(M, 2)) + 1


    if M > (2 ** (B-2)):
        return "IMPOSSIBLE"

    for i in range(B-1):
        for j in range(i+1, B):
            res[i][j] = 1

    res[B-1] = [0] * B

    if M < (2 ** (B-2)):
        res[0][B-1] = 0
        for i in range(B-2):
            d = (M >> i) %2

            print "i, d:", i,d
            res[0][B - 2 - i] = d


    str_res = "POSSIBLE"
    for r in res:
        str_res += '\n'
        str_res += ''.join([str(c) for c in r])

    return str_res



################################################################################

def read_case(f):
    return read_ints(f)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for i in range(R)]

def main():
    if len(sys.argv) != 2:
        print 'usage: python <file_name> <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as w:
        count = read_int(f)
        for i in xrange(1, count + 1):
            case_inputs = read_case(f)
            write_case(w, i, solve(case_inputs))

if __name__ == "__main__":
    main()


