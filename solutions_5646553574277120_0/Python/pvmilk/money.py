#!/usr/bin/python
#
# ./template.py -i template.inpt 
#

import math
from optparse import OptionParser
from itertools import permutations
from itertools import combinations
from sets import Set

def parse_input(input_fname):
    input_arr = []
    f = open(input_fname, "r")

    # READ TESTCASE NUMBER
    testcase_num = int(f.readline())

    for t in range(0, testcase_num):
        line1 = f.readline().rstrip('\n').split()
        line1_int   = map(lambda x: int(x), line1)

        line2 = f.readline().rstrip('\n').split()
        line2_int   = map(lambda x: int(x), line2)

        assert(len(line1_int) == 3)
        assert(len(line2_int) == line1_int[1])

        input_arr.append([line1_int[0], line1_int[1], line1_int[2], line2_int, line2])

        # EXAMPLE #
        #line1       = f.readline().rstrip('\n').split()
        #line2       = f.readline().rstrip('\n').split()
        #line2_int   = map(lambda x: int(x), line2)
        #input_arr.append([int(line1[0]), int(line1[1]), line2_int])

    return input_arr

def write_output(output_fname, output_arr):
    f = open(output_fname, "w")
    for i in range(0, len(output_arr)):
        str_line = "Case #%d: %d\n" %(i+1, output_arr[i])
        f.write(str_line)
    f.close()

def get_all_sum(Ds_sorted_int):

    Ds_str = map(lambda x: str(x), Ds_sorted_int)

    possible_combi = []
    for i in range(0, len(Ds_str)):
        for p in combinations(Ds_str, i+1):
            possible_combi.append(p);

    all_sum = Set([])
    for combi in possible_combi:
        cur_sum = 0
        for i in range(0, len(combi)):
            cur_sum = cur_sum + int(combi[i])
        all_sum.add(cur_sum)

    return all_sum

def calculate_input(inpt):
    C       = inpt[0]
    D       = inpt[1]
    V       = inpt[2]
    Ds_int  = inpt[3]

    desired_sums = Set(range(1, V+1))

#    possible_combi = []
#    for i in range(0, len(Ds_str)):
#        for p in combinations(Ds_str, i+1):
#            possible_combi.append(p);
#
#
#    all_sum = Set([])
#    for combi in possible_combi:
#        cur_sum = 0
#        for i in range(0, len(combi)):
#            cur_sum = cur_sum + int(combi[i])
#        all_sum.add(cur_sum)
    added_num = 0
    all_sum = get_all_sum(Ds_int)
    left_desired_sum = desired_sums-all_sum
    while len(left_desired_sum) != 0:
        added_num = added_num + 1
        Ds_int.append(min(list(left_desired_sum)))
        Ds_int = sorted(Ds_int)

        all_sum = get_all_sum(Ds_int)
        left_desired_sum = desired_sums-all_sum

    return added_num

def main(input_fname, output_fname):
    print ">>>>>>>> READ_INPUT"
    input_arr = parse_input(input_fname)
    print "len(input_arr) : %d" %(len(input_arr))
    #print input_arr

    print ">>>>>>>> CALCULATE OUTPUT"
    output_arr = []
    for i in range(0, len(input_arr)):
    #for i in range(3, len(input_arr)):
        output_arr.append(calculate_input(input_arr[i]))
        print "Finish testcase : %d" %(i)

    print ">>>>>>>> WRITE_OUTPUT"
    write_output(output_fname, output_arr)

if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option("-i", type="str", dest="input_fname")

    (options, args) = parser.parse_args()
    if options.input_fname != None:
        i_fname = options.input_fname
        o_fname = options.input_fname + ".out"

        print "INPUT FILE : %s" %(i_fname)
        print "OUTPUT FILE : %s" %(o_fname)

        main(i_fname, o_fname)
