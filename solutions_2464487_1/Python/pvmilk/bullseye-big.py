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
        assert(len(ipt_strs) == 2)
        input_arr.append(( int(ipt_strs[0]), int(ipt_strs[1]) ))

    return input_arr

def write_output(output_fname, output_arr):
    f = open(output_fname, "w")
    for i in range(0, len(output_arr)):
        str_line = "Case #%d: %d\n" %(i+1, output_arr[i])
        f.write(str_line)
    f.close()

def req_t(n, r):
    return n*(2*r+2*n-1)

def calculate_input(inpt):
    r = inpt[0]
    t = inpt[1]

    #binary search n = 10**9 for biggest one
    rn = 10**18
    ret_n = -1
    hi = rn
    lo = 1
    while lo < hi:
        mid = (lo+hi)//2
        midval          = req_t(mid, r)
        midval_pre      = req_t(mid-1, r)

        if midval < t:
            lo = mid+1
        elif midval > t:
            if midval_pre < t:
                ret_n = mid-1
                break;
            else:
                hi = mid
        else:
            ret_n = mid
            break;

    assert(ret_n > 0)
    return ret_n

def main(input_fname, output_fname):
    print ">>>>>>>> READ_INPUT"
    input_arr = parse_input(input_fname)
    print "len(input_arr) : %d" %(len(input_arr))

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
