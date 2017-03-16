#python 2.7

import sys
import math
import string
import itertools

def genPerms(S):
    if len(S) == 1:
	if S == "?":
	    return range(0,10)
	else:
	    return [int(S)]
    ret = set()
    remainingPerms = genPerms(S[1:])
    for p in genPerms(S[0]):
	for x in remainingPerms:
	    res = str(p) + str(x)
	    extra0 = "0"*(len(S) - len(res))
	    ret.add(int(str(p) +extra0+ str(x)))
    return ret

def getMin(L):
    minVal = 0xFFFFFFFF
    candidates = []
    for l in L:
	candMin = abs(l[0] - l[1])
	if candMin == minVal:
	    candidates.append(l)
	elif candMin < minVal:
	    candidates = [l]
	    minVal = candMin 

    val1 = min([c[0] for c in candidates])
    val2cands = []
    for c in candidates:
	if c[0] == val1:
	    val2cands.append(c[1])
    return [val1, min(val2cands)]

def solve(CJ):
    C = CJ[0]
    J = CJ[1]
    
    Cperm = genPerms(C)
    Jperm = genPerms(J)

    ret = getMin(list(itertools.product(*[list(Cperm), list(Jperm)])))
    ret0 = str(ret[0])
    ret0 = "0" * (len(C) - len(ret0)) + ret0
    ret1 = str(ret[1])
    ret1 = "0" * (len(C) - len(ret1)) + ret1
    return ret0 + " " + ret1
    
def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        res = solve(split_input[i+1].split(" "))
        output_file.write("Case #" + str(i+1) + ": " + str(res) + "\n")
        print "Case #" + str(i+1) + ": " + str(res) 
if __name__ == "__main__":
    main()
