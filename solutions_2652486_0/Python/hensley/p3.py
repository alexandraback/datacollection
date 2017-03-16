import numpy as np
import os
import re
from collections import defaultdict

def make_dict(num):
    num = str(num)
    probs = defaultdict(int)
    probs[1] += 1.0/8.0
    probs[int(num[0])] += 1.0/8.0
    probs[int(num[1])] += 1.0/8.0
    probs[int(num[2])] += 1.0/8.0
    probs[int(num[0])*int(num[1])] += 1.0/8.0
    probs[int(num[0])*int(num[2])] += 1.0/8.0
    probs[int(num[1])*int(num[2])] += 1.0/8.0
    probs[int(num[0])*int(num[1])*int(num[2])] += 1.0/8.0
    return probs

def analyze(seq):
    maxlike = 0.0
    bestguess = 000
    for key in master.keys():
        like = 1.0
        for i in range(len(seq)):
            like *= master[key][int(seq[i])]
        if like > maxlike:
            bestguess = key
    return bestguess

def main():
    infile = "Csmall.in"
    inf = open(infile, 'r')

    outfile = "Csmall.out"
    outf = open(outfile, 'w')
    outf.write("Case #1:\n")

    global master
    master = defaultdict(lambda : defaultdict(float)) 

    nums = np.array([2,3,4,5])
    for i in range(len(nums)):
        for j in range(len(nums)):
            for k in range(len(nums)):
                ident = int(str(nums[i]) + str(nums[j]) + str(nums[k]))
                master[ident] = make_dict(ident)

    lnum = 1
    case = 0
    totcase = 0
    for line in inf:
        if (lnum > 2):
            lstring = line.split()
            guess = analyze(lstring)
            outf.write(str(guess) + "\n")
        lnum += 1
            


if __name__ == '__main__':
     main()
