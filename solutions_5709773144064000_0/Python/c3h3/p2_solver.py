'''
Created on Apr 13, 2014

@author: c3h3
'''

import sys


def total_cost(F_cost, gen_speed, target_vol):
    return F_cost + target_vol / gen_speed


if __name__ == '__main__':
    assert len(sys.argv) > 1
    input_filename = str(sys.argv[1])

    with open(input_filename, "r") as input_file:
        input_file_read = input_file.read()

    input_file_lines = input_file_read.split("\n")
    input_file_lines
    n_cases = int(input_file_lines[0])
    for i_case in range(n_cases):
        C, F, X = tuple(map(float, input_file_lines[1:][i_case].split()))
        F_cost = 0.0
        gen_speed = 2.0
        target_vol = X
        new_F_cost = F_cost + C / gen_speed
        new_gen_speed = gen_speed + F

        while total_cost(new_F_cost, new_gen_speed, X) < total_cost(F_cost, gen_speed, X):
            F_cost = new_F_cost
            gen_speed = new_gen_speed
            new_F_cost = F_cost + C / gen_speed
            new_gen_speed = gen_speed + F

        print "Case #%s: %.7f" % (i_case + 1, total_cost(F_cost, gen_speed, X))


