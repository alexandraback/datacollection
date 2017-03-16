#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import datetime

def get_a_b_p(line1, line2):
    line1 = line1.replace('\n', '')
    item_list1 = line1.split(' ')
    line2 = line2.replace('\n', '')
    item_list2 = line2.split(' ')
    return int(item_list1[0]), int(item_list1[1]), [float(x) for x in item_list2]

def solve(a, b, p_list):
    pp_list = [p_list[0]]
    for p in p_list[1:]:
        pp_list.append(pp_list[len(pp_list) - 1] * p)
    pp_list.append(1)

    value_list = []
    for i in range(0, a + 2):
        if i != a + 1:
            prov = pp_list[a - i - 1]
            num_key_time_to_end = 2 * i + b - a + 1
            value = prov * num_key_time_to_end + (1- prov) * (num_key_time_to_end + b + 1)
        else:
            value = b + 2
        value_list.append(value)
    return min(value_list)

def main():
    if len(sys.argv) < 2:
        print 'Usage : %s <problem_file>' % sys.argv[0]
        return

    # problem file
    in_file_name = sys.argv[1]
    out_file_name = in_file_name.replace('in', 'out')

    f = open(in_file_name, 'r')
    lines = f.readlines();
    f.close()

    num_test = int(lines[0].replace('\n', ''))
    test_count = 1
    while test_count <= num_test:
        a, b, p_list = get_a_b_p(lines[2 * test_count - 1], lines[2 * test_count])
        result = solve(a, b, p_list)
        output = 'Case #%d: %.6f' % (test_count, result)
        print output
        f = open(out_file_name, 'a')
        f.write(output + '\n')
        f.close()
        test_count += 1

if __name__ == '__main__':
    main()
