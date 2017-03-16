import numpy as np
import math

class Case:
    def __init__(self):
        self.nb_pancakes = []

    def solve(self):
        nb_minutes = np.inf
        nb_special_minutes = 0
        while True:
            m = max(self.nb_pancakes)
            k = self.nb_pancakes.index(m)
            nb_minutes = min(nb_minutes, nb_special_minutes + m)

            if m <= 3:
                break

            self.nb_pancakes.append(m / 2)
            self.nb_pancakes[k] -= self.nb_pancakes[-1]
            nb_special_minutes += 1

        return str(nb_minutes)


def read_case(file):
    case = Case()
    file.readline()
    line = map(int, file.readline().split(' '))
    case.nb_pancakes = line
    return case


def main():
    filename_in = 'B-small-attempt0.in'
    filename_out = 'B-small-attempt0.out'
    file_in = open(filename_in)
    file_out = open(filename_out, 'w')

    nb_case = int(file_in.readline())

    for k in range(1, nb_case + 1):
        case = read_case(file_in)
        file_out.write('Case #' + str(k) + ': ' + case.solve() + '\n')

    file_out.close()


if __name__ == '__main__':
    main()