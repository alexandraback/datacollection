#!/usr/bin/env python
#from collections import defaultdict
from decimal import Decimal as D

def recycle(a, b):
    zz = str(a) * 2
    return str(b) in zz

def range_recycle(a, b):
    count = 0
    for i in range(a, b):
        for j in range(i+1, b+1):
            if recycle(i, j):
                count += 1
    return count

def get_total(A, B, i, net_p):
    x = (B - A + 1 + 2 * i)
    return x * net_p + (1 - net_p) * (B + 1 + x)
    
    
    
def processFile(fname):
    def processCase(f):
        A, B = map(int, f.readline().strip("\n").split(" "))
        probabilities = map(D, f.readline().strip("\n").split(" "))
        
        last_p = 1
        for i, p in enumerate(probabilities):
            probabilities[i] = last_p * p
            last_p = p
        #print probabilities
        #for i in range(0, A):
        #    print i, A, get_total(A, B, i, probabilities[-(i + 1)])
        if (get_total(A, B, A, 1) < 2 +B):
            raise Exception
        strokes = min(get_total(A, B, i, probabilities[-(i + 1)]) for i in range(0, A))
        return min(strokes, 2 + B)
    
    with open(fname, "r") as f:
        cases = int(f.readline().strip("\n"))
        output = ""
        for case in range(cases):
            a = processCase(f)
            output += "Case #%d: %.6f\n" % (case + 1, a)
        print output
    with open("ans"+fname, "w") as f:
        f.write(output)

processFile("sample.txt")
processFile("A-small-attempt1.in")
#processFile("B-large.in")