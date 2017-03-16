import sys

import numpy as np 
from collections import Counter

letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def fashion(inputline):
    jackets, pants, shirts, limit = [int(s) for s in inputline.split(" ")]

    cjp = Counter()
    cjs = Counter()
    cps = Counter()

    retlist = []
    for j in range(jackets):
        for pp in range(pants):
            p = (j+pp+1) % pants
            for ss in range(shirts):
                s = (p+ss+1) % shirts
                outfit = (j, p, s)
                print(outfit)
                print(cjs)
                print(cps)
                print(cjp)
                print()
                if cjs[(j, s)]<limit and cps[(p, s)]<limit and cjp[(j, p)]<limit:
                    retlist.append("{} {} {}".format(j+1, p+1, s+1))
                    cjp[(j, p)] += 1
                    cjs[(j, s)] += 1
                    cps[(p, s)] += 1

    ret = "{}\n".format(len(retlist)) + "\n".join(retlist)

    return ret



if "__main__" == __name__:
    
    # print(sys.argv[1])
    inputfile = sys.argv[1]

    out = []
    with open(inputfile, 'r') as f:
        T = int(f.readline())
        for _ in range(T):
            out.append(fashion(f.readline()))
    
    with open("out_"+inputfile, 'w') as f:
        for i, o in enumerate(out):
            f.write("Case #{}: {}\n".format(i+1, o))
            print("Case #{}: {}".format(i+1, o))
