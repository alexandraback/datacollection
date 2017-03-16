#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import datetime

def get_s(line):
    line = line.replace('\n', '')
    item_list = line.split(' ')
    return [int(x) for x in item_list[1:]]

def solve(s_list):
    total = float(sum(s_list))
    ave = total * 2 / len(s_list)
    over_list = filter(lambda x: x>ave, s_list)
    over_total = sum(over_list)
    ave = (total * 2 - over_total) / (len(s_list) - len(over_list))

    ret_list = []
    for s in s_list:
        print s, ave
        dif = ave - s
        if dif > 0:
            ret_list.append((dif / total) * 100)
        else:
            ret_list.append(0)
    return ret_list


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
        s_list = get_s(lines[test_count])
        result_list = solve(s_list)
        output = 'Case #%d:' % (test_count)
        for result in result_list:
            output += ' %.6f' % (result)
        print output
        f = open(out_file_name, 'a')
        f.write(output + '\n')
        f.close()
        test_count += 1

if __name__ == '__main__':
    main()
