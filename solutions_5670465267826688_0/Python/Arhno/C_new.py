import numpy as np
import math


prod = { 1 : {1: (1,  1 ), 'i': ( 1, 'i'), 'j': ( 1, 'j'), 'k': ( 1, 'k')},
        'i': {1: (1, 'i'), 'i': (-1,  1 ), 'j': ( 1, 'k'), 'k': (-1, 'j')},
        'j': {1: (1, 'j'), 'i': (-1, 'k'), 'j': (-1,  1 ), 'k': ( 1, 'i')},
        'k': {1: (1, 'k'), 'i': ( 1, 'j'), 'j': (-1, 'i'), 'k': (-1,  1 )}}


def mul_right((s_old, v_old), e):
    (s_new, v_new) = prod[v_old][e]
    s_new *= s_old
    return s_new, v_new


def mul_left(e, (s_old, v_old)):
    (s_new, v_new) = prod[e][v_old]
    s_new *= s_old
    return s_new, v_new


class Case:
    def __init__(self):
        self.period = ''
        self.repeat = 0
        self.index_i = []
        self.index_k = set([])


    def solve(self):
        len_period = len(self.period)
        len_seq = len_period * self.repeat

        p_start = 0
        cur_val = (1, 1)
        while p_start < len_seq:
            next_e = self.period[p_start % len_period]
            cur_val = mul_right(cur_val, next_e)
            if cur_val == (1, 'i'):
                self.index_i.append(p_start)
            p_start += 1

        # Discard some cases (ijk = -1 so the entire product needs to be -1)
        if cur_val != (-1, 1):
            return 'NO'

        p_end = len_seq - 1
        cur_val = (1, 1)
        max_p_j = -1
        while p_end > 0:
            next_e = self.period[p_end % len_period]
            cur_val = mul_left(next_e, cur_val)
            if cur_val == (1, 'k'):
                self.index_k.add(p_end)
                if max_p_j == -1:
                    max_p_j = p_end
            p_end -= 1

        for p_i in self.index_i:
            p_j = p_i + 1
            cur_val = (1, 1)
            while p_j <= max_p_j:
                if p_j in self.index_k and cur_val == (1, 'j'):
                    return 'YES'
                next_e = self.period[p_j % len_period]
                cur_val = mul_right(cur_val, next_e)

                p_j += 1

        return 'NO'

def read_case(file):
    case = Case()
    line = file.readline().split(' ')
    case.repeat = int(line[1])
    line = file.readline()
    case.period = line[:-1]
    return case


def main():
    filename_in = 'C-small-attempt5.in'
    filename_out = 'C-small-attempt5.out'
    file_in = open(filename_in)
    file_out = open(filename_out, 'w')

    nb_case = int(file_in.readline())

    for k in range(1, nb_case + 1):
        case = read_case(file_in)
        to_write = 'Case #' + str(k) + ': ' + case.solve() + '\n'
        print to_write[:-1]
        file_out.write(to_write)

    file_out.close()


if __name__ == '__main__':
    main()