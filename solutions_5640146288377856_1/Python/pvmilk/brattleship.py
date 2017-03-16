#!/usr/bin/python
#
# ./template.py -i template.inpt 
#

import math
from optparse import OptionParser

def parse_input(input_fname):
    input_arr = []
    f = open(input_fname, "r")

    # READ TESTCASE NUMBER
    testcase_num = int(f.readline())

    for t in range(0, testcase_num):
        ipt_strs = f.readline().rstrip('\n').split()
        input_arr.append(map(lambda x: int(x), ipt_strs))

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

def calculate_input(inpt):
    R = inpt[0]
    C = inpt[1]
    W = inpt[2]

    num_trials = C/W + W;

    if C%W == 0:
        num_trials = num_trials -1

    return R*num_trials

def main(input_fname, output_fname):
    print ">>>>>>>> READ_INPUT"
    input_arr = parse_input(input_fname)
    print "len(input_arr) : %d" %(len(input_arr))
    #print input_arr

    print ">>>>>>>> CALCULATE OUTPUT"
    output_arr = []
    for i in range(0, len(input_arr)):
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
