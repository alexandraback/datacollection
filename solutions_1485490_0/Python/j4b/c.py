#!/usr/bin/python

import sys
import functools
import operator

#sys.setrecursionlimit(90000)

def solve(boxes, toys, produced):
    #print("called: " + str(boxes) + " - " + str(toys) + " - " + str(produced))
    if not boxes or not toys:
        #print ("return")
        return produced

    (bnum, btype) = boxes.pop(0)
    (tnum, ttype) = toys.pop(0)

    n = min(bnum, tnum)
    #print(n)

    # match
    if btype == ttype:
        if bnum - n != 0:
            boxes.insert(0, (bnum - n, btype))
        if tnum - n != 0:
            toys.insert(0, (tnum - n, ttype))

        return solve(boxes, toys, produced + n)

    else:
        # throw away boxes
        boxes_c = list(boxes)
        toys_c = list(toys)

        toys.insert(0, (tnum, ttype))

        sol1 = solve(boxes, toys, produced)

        #if pop:
        #    boxes.pop(0)
        #toys.pop(0)
        
        # throw away toys
        boxes_c.insert(0, (bnum, btype))
        
        sol2 = solve(boxes_c, toys_c, produced)

        return max(sol1, sol2)
    

def main():
    N = int(sys.stdin.readline()) # number of testcases
    results = []
    for i in range(N):
        # use something like:
        sys.stdin.readline()
        input1 = [int(x) for x in sys.stdin.readline().split()]
        boxes = [(input1[2*i], input1[2*i+1]) for i in range(len(input1)/2)]
        input2 = [int(x) for x in sys.stdin.readline().split()]
        toys = [(input2[2*i], input2[2*i+1]) for i in range(len(input2)/2)]
        result = solve(boxes, toys, 0)
        results.append(result)
        #print ("Case #%s: %s" % (i+1, result))

    for i in range(N):
        print ("Case #%s: %s" % (i+1, results[i]))
        


if __name__ == '__main__':
    main()
