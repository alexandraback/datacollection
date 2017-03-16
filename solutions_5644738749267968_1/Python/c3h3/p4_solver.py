'''
Created on Apr 13, 2014

@author: c3h3
'''

import sys
import numpy as np
from PlaYdata.util import tools


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
    case_seps = map(lambda x: 3 * x + 1, range(n_cases + 1))
    case_seps_idx = list(tools.ngram(case_seps, 2))

    for i_case in range(n_cases):
        one_case_idx = case_seps_idx[i_case]
        one_case_data = input_file_lines[one_case_idx[0]:one_case_idx[1]]
        one_case_n_blocks = int(one_case_data[0])

        naomi_block = np.array(map(float, one_case_data[1].split()))
        naomi_block_ones = np.ones(naomi_block.shape)

        ken_block = np.array(map(float, one_case_data[2].split()))
        ken_block_ones = np.ones(ken_block.shape)

        total_w = np.r_[naomi_block, ken_block]
        total_ones = np.r_[naomi_block_ones, -ken_block_ones]

        data = np.array(zip(total_w, total_ones), dtype=np.dtype([("w", total_w.dtype), ("o", total_ones.dtype)]))

        o_list = data["o"][data["w"].argsort()].tolist()
        o_list.reverse()
        o_list_array = np.array(o_list)

        first_ans = one_case_n_blocks - int(np.max(np.cumsum(-o_list_array)))
        second_ans = int(np.max(np.cumsum(o_list_array)))

        print "Case #%s: %d %d" % (i_case + 1, first_ans, second_ans)



