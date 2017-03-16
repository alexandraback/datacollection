import math
import fileinput

import time

def is_pali(x):
    s = str(x)
    return False not in [x[0]==x[1] for x in zip(s,s[::-1])]

def check_num(x):
    return is_pali(x) and is_pali(x*x)

def check_range(a,b,good_nums):
    count = 0
    for x in good_nums:
        val = x*x
        if val >= a and val <= b:
            count += 1
    return count

def main():
    it = fileinput.input()
    start = time.clock()
    slow_flow = False
    if slow_flow:
        max_val = 25*(10**6)
        good_nums = []
        for i in xrange(1,max_val):
            if i % (10**6) == 0:
                print i
            if is_pali(i) and is_pali(i*i):
                good_nums.append(i)
    else:
        # Cached results of a previous run of the above slow flow
        good_nums = [1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002]
    end = time.clock()
    #print end-start,"Ready, nums:",good_nums
    num_cases = int(it.next())
    for i,case in enumerate(it):
        a,b = [long(x) for x in case.split()]
        print "Case #%d: %d" % (i+1, check_range(a,b,good_nums))
        
if __name__ == "__main__":
    main()
