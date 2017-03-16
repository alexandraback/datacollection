from codejam import *
import itertools

def read_file(f):
    s = read_string(f)
    return s

def solver(case):
    c, j = case.split(' ')
    ans_c = []
    ans_j = []
    for i in range(len(c)):
        if c[i] == '?':
            ans_c.append(list(range(10)))
        else:
            ans_c.append([int(c[i])])
        if j[i] == '?':
            ans_j.append(list(range(10)))
        else:
            ans_j.append([int(j[i])])
    def convert(tup):
        return int(''.join(list(map(str, tup))))
    c_list = list(map(convert, itertools.product(*ans_c)))
    j_list = list(map(convert, itertools.product(*ans_j)))
    output_c = c_list[0]
    output_j = j_list[0]
    smallest = abs(c_list[0] - j_list[0])
    for a in c_list:
        for b in j_list:
            if abs(a-b) < smallest:
                smallest = abs(a-b)
                output_c = a
                output_j = b
    return str(output_c).zfill(len(c)) + ' ' + str(output_j).zfill(len(c))

solve('B-small-attempt2', read_file, solver)
