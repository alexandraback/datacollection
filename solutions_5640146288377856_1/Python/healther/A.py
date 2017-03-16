import sys
#import argpase

import numpy as np 

def solvecase(case):
    # collect caseoutput
    caseout = ""

    r,c,w = case
    print(r,c,w) 
    shots = r * int(c/w) # create search grid with spacing w-1, success with last hit 
    shots = r * int(c/w) + w - (c%w==0)

    caseout = shots
    return caseout

def test():
    with open("out_giveninp.txt", 'r') as f:
        myout = f.read()
    with open("givenout.txt", 'r') as f:
        givenout = f.read()
    if givenout+'\n'!=myout:
        print('failed')
        print('givenout')
        print(givenout)
        print(myout)
    else:
        print('success')

if "__main__" == __name__:
    
    print(sys.argv[1])
    inputfile = sys.argv[1]


    with open(inputfile, 'r') as f:
        # number of test cases
        T = int(f.readline())
        cases = []
        for _ in range(T):
            # handle one test case here
            r,c,w = f.readline().split()
            cases.append((int(r),int(c),int(w)))
    # collect out 
    out = ""


    for i in range(T):
        out += "Case #{}: {}\n".format(i+1, solvecase(cases[i]))

    with open("out_"+inputfile, 'w') as f:
        f.write(out)

    if "giveninp.txt"==inputfile:
        test()
