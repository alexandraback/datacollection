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
        ipt_strs = f.readline().split()
        assert(len(ipt_strs) == 3)
        line1 =  [int(ipt_strs[0]), int(ipt_strs[1]), int(ipt_strs[2]) ]
        ipt_strs = f.readline().split()
        assert(len(ipt_strs) == line1[2])
        line2 = []
        for i in range(0, line1[2]):
            line2.append(int(ipt_strs[i]))
        input_arr.append((line1, line2))

    return input_arr

def write_output(output_fname, output_arr):
    f = open(output_fname, "w")
    for i in range(0, len(output_arr)):
        str_line = "Case #%d: %s\n" %(i+1, output_arr[i])
        f.write(str_line)
    f.close()

def max_gain(e, r, vs):
    if(len(vs) == 1):
        return vs[0]*e
    else:
        choice0 = r*vs[0] + max_gain(e, r, vs[1:len(vs)])
        choice1 = e*vs[0] + sum(vs[1:len(vs)])*r
        return max(choice0, choice1)

def calculate_input(inpt):
    e     = inpt[0][0]
    r     = inpt[0][1]
    n     = inpt[0][2]
    vs    = inpt[1]

    ret_gain = 0
    if (r>=e):
        ret_gain = sum(vs)*e
    else:
        # recursive
        ret_gain = max_gain(e, r, vs)
        #max_v = max(vs)
        #max_idx = vs.index(max_v)
        #ret_gain = sum(vs)*r
        #ret_gain = ret_gain + max_v*(e-r)

    return ret_gain

def main(input_fname, output_fname):
    print ">>>>>>>> READ_INPUT"
    input_arr = parse_input(input_fname)
    print "len(input_arr) : %d" %(len(input_arr))
    #print input_arr

    print ">>>>>>>> CALCULATE OUTPUT"
    output_arr = []
    for i in range(0, len(input_arr)):
        output_arr.append(calculate_input(input_arr[i]))

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
