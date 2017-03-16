#!/usr/bin/env python
#coding: UTF-8
'''
I/O framework for the Google Code Jam contest

Created on Apr 25, 2012

@author: Samuel Groß
'''

INPUTFILE  = "/home/sam/Desktop/small.in"
OUTPUTFILE = "/home/sam/Desktop/small.out"

LINES_PER_PROBLEM = 2


# ------------------- #
#      Functions      #
# ------------------- #

def solve(amin, motes):
    if amin == 1:
        return len(motes)
    motes = sorted(motes) 
    operations = 0
    min_ops = 10000000000000000
    num = 0
    for mote in motes:
        if mote < amin:
            # eat
            amin += mote
        else:
            # delete all above
            if min_ops > operations + len(motes) - num:
                min_ops = operations + len(motes) - num

           # or add motes until eatable
            while amin <= mote:
                amin += amin - 1
                operations += 1
            amin += mote
        num += 1

    # all eaten
    if min_ops > operations:
        min_ops = operations
            

    return min_ops





if __name__ == '__main__':
    
    infile = open(INPUTFILE, 'r')
    outfile = open(OUTPUTFILE, 'w')
    
    testcases = int(infile.readline())
    counter = 1


    for i in range(testcases):
        amin = int(infile.readline().split(" ")[0])    
        motes = map(int, infile.readline().split(" ")) 
        sol = solve(amin, motes)	
        print("[*] Case %i solved, %.2f%% done" % (counter, float(counter) * 100 / testcases))
        outfile.write("Case #%i: %s\n" % (counter, sol))
        counter += 1 
        
