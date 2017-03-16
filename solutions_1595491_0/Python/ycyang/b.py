#!/usr/bin/python
import sys

def process(num, sup, best, totals):
    count = 0
    s = sup
    for i in totals:
    	if i < best:
    		continue
    	if i < 3*best -4:
    		continue
        if i >= 3*best-2:
            count += 1
            continue
        if (i == 3*best-3) and (sup > 0):
            count += 1
            sup -= 1
            continue
        if (i == 3*best-4) and (sup > 0):
            count += 1
            sup -= 1
            continue
    return count
    
def main():
    T = int(sys.stdin.readline().strip())
    x = 1
    while x <= T:
        instr = sys.stdin.readline().strip().split(' ')
        case = [int(c) for c in instr]
        num = case[0]
        sup = case[1]
        best = case[2]
        totals = case[3:]
        #print totals
        print "Case #%d: %d" %(x, process(num,sup,best,totals))
        x += 1
    return

main()
