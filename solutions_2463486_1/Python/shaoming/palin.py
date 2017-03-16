#!/usr/bin/env python

import sys, os, re
import itertools

#---------------------------------------------------
# Variable 
#---------------------------------------------------
palin_square = []
max_value1 = 0
max_value2 = 0
max_number = 0

#---------------------------------------------------
# Function 
#---------------------------------------------------

def gen_all_palin_square(target):
    global palin_square, max_value1, max_value2, max_number

    while max_value2 < target:
        max_number += 1

        for v in gen_palin(max_number):
            max_value1 = v
            max_value2 = max_value1 * max_value1 
            if is_palin(max_value2):
                palin_square.append(max_value2)
    return

def cnt_palin_square(st, ed):
    cnt = 0
    for v in palin_square:
        if v >  ed: break
        if v >= st: cnt += 1 
    return cnt
        
def gen_palin(num):
    num_half = (num + 1) // 2
    for vec in itertools.product('0123456789', repeat=num_half):
        if vec[0] == '0': continue
        if num % 2 == 1:
            vec1 = vec + vec[0:-1][::-1]
        else:
            vec1 = vec + vec[::-1]
        assert len(vec1) == num
        val = int(''.join(vec1))
        yield val 
    return

def is_palin(val):
    s = str(val)
    if s != s[::-1]:
        return False
    return True

def load_file(filename):
    with open(filename, 'rU') as f:
        number = int(f.readline())

        for i in range(number):
            st, ed = [int(v) for v in f.readline().split()]
            gen_all_palin_square(ed)
            cnt = cnt_palin_square(st, ed)
            print 'Case #%d: %d' % (i+1, cnt)
            continue
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    load_file (sys.argv[1])
    #for v in gen_palin(4):
    #    print v, is_palin(v)
    #gen_all_palin_square(1000000000000000)
    #for v in palin_square:
    #    print v

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


