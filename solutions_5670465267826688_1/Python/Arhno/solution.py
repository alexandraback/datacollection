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


def reduce(sequence):
    res = (1, 1)
    for e in sequence:
        res = mul_right(res, e)

    return res


def repeat((s, v), times):
    if times == 0:
        return 1, 1

    true_sign = (s ** (times % 2)) * (      ((-1) ** ((times / 2) % 2)) if v != 1 else 1       )
    true_value = v if times % 2 == 1 else 1
    return true_sign, true_value


def find_i(start, sequence):
    nb_elem = 0
    for e in sequence:
        nb_elem += 1
        start = mul_right(start, e)
        if start == (1, 'i'):
            return nb_elem

    return -1


def find_k(sequence, end):
    nb_elem = 0
    for k in range(1, len(sequence) + 1):
        nb_elem += 1
        end = mul_left(sequence[-k], end)
        if end == (1, 'k'):
            return nb_elem

    return -1


class Case:
    def __init__(self):
        self.period = ''
        self.repeat = 0


    def solve(self):
        len_period = len(self.period)
        len_seq = len_period * self.repeat

        # Quick test to discard some obvious dead ends
        ## too short anyway
        if len_seq < 3:
            return 'NO'
        ## only one kind of letter in the sequence => no way to get the other two
        distinct = set([])
        for e in self.period:
            distinct.add(e)
        if len(distinct) == 1:
            return 'NO'

        ## ijk = -1 so the entire sequence needs to reduce to -1
        period_reduction = reduce(self.period)
        sequence_reduction = repeat(period_reduction, self.repeat)
        if sequence_reduction != (-1, 1):
            return 'NO'

        # Now we only need to find i at the beginning and k at the ending (in those cases, the middle section is j)
        found_i = False
        nb_period_start = 0
        i_pos = 0
        for nps in range(4):
            start = repeat(period_reduction, nps)
            i_pos = find_i(start, self.period)
            if i_pos > 0:
                nb_period_start = nps
                found_i = True
                break

        if not found_i:
            return 'NO'

        found_k = False
        nb_period_end = 0
        k_pos = 0
        for npe in range(4):
            end = repeat(period_reduction, npe)
            k_pos = find_k(self.period, end)
            if k_pos > 0:
                nb_period_end = npe
                found_k = True
                break

        if not found_k:
            return 'NO'

        if nb_period_start + i_pos + k_pos + nb_period_end >= len_seq:
            return 'NO'

        return 'YES'

def read_case(file):
    case = Case()
    line = file.readline().split(' ')
    case.repeat = int(line[1])
    line = file.readline()
    case.period = line[:-1]
    return case


def main():
    filename_in = 'C-large.in'
    filename_out = 'C-large.out'
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