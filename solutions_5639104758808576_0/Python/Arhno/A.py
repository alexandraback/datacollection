import numpy as np
import math

class Case:
    def __init__(self):
        self.nb_per_shiness = []

    def solve(self):
        nb_to_invite = 0
        nb_before = 0
        for k in range(len(self.nb_per_shiness)):
            to_add = 0 if nb_before >= k else k - nb_before
            nb_before += to_add + self.nb_per_shiness[k]
            nb_to_invite += to_add

        return str(nb_to_invite)


def read_case(file):
    case = Case()
    line = file.readline().split(' ')[1]
    case.nb_per_shiness = map(int, line[:-1])
    return case


def main():
    filename_in = 'A-small-attempt0.in'
    filename_out = 'A-small-attempt0.out'
    file_in = open(filename_in)
    file_out = open(filename_out, 'w')

    nb_case = int(file_in.readline())

    for k in range(1, nb_case + 1):
        case = read_case(file_in)
        file_out.write('Case #' + str(k) + ': ' + case.solve() + '\n')

    file_out.close()


if __name__ == '__main__':
    main()