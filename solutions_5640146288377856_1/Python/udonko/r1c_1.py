#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:   gcj 2015 r1c
#
# Author:      udonko
#
# Created:     10/05/2015
# Copyright:   (c) udonko 2015
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import sys

def resolve(r,c,w):
    if w==1:
        return r*c
    # when ship in the row
    step1 = c // w
    width_to_find = c - (step1-1)*w

    row_with_ship = step1 + w - 1
    if width_to_find != w:
        row_with_ship += 1

    row_without_ship = step1

    retval = row_with_ship + row_without_ship * (r-1)

    return retval

def test():
    def testcase(r,c,w):
        print("r:{0} c:{1} w:{2} ret:{3}".format(r,c,w,resolve(r,c,w)))
    testcase(1,4,2)
    testcase(1,7,7)
    testcase(2,5,1)
    testcase(2,14,7)
def main():
    with open("in.txt","r") as infile:
        with open("out_r1c_1.txt","w") as outfile:
            num_case = int(infile.readline())
            for index in range(num_case):
                line = infile.readline()
                r,c,w=map(int,line.split())
                turn=resolve(r,c,w)
                outstr="Case #{0}: {1}\n".format(index+1, turn)
                outfile.write(outstr)
if __name__ == '__main__':
    main()
    #test()
