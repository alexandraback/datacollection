import sys
#import argpase

import numpy as np 

def reach(target, coins, multiple, canreach):
    if len(coins)==1:
        if coins[0]!=1:
            additionalcoins = [1]
    target


    return additionalcoins

def solvecase(case):
    c,d,v,ds = case
    # collect caseoutput
    maxvalue = v
    maxcoins = c
    coins = np.array(ds)
    coins.sort()

    for i in range(maxvalue+1)[1:]:
        tmp = np.copy(i)
        usablecoins = coins[coins<i]
        for c in coins[::-1]:
            for _ in range(maxcoins):
                if tmp>=c:
                    tmp -= c
        if tmp>0:
            add = i-tmp + 1
            coins = np.array([t for t in coins] + [add])
            coins.sort()
    print(coins)
    return len(coins)-d

    

def test():
    with open("out_giveninp.txt", 'r') as f:
        myout = f.read()
    with open("givenout.txt", 'r') as f:
        givenout = f.read()
    if givenout!=myout:
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
            c,d,v = f.readline().split()
            ds = f.readline().split()
            ds = [int(i) for i in ds]
            cases.append((int(c), int(d), int(v), ds))
    # collect out file
    out = ""


    for i in range(T):
        out += "Case #{}: {}\n".format(i+1, solvecase(cases[i]))

    with open("out_"+inputfile, 'w') as f:
        f.write(out)

    if "giveninp.txt"==inputfile:
        test()
