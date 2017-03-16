#! /usr/bin/env python

## Written by Joey Tuong- deuterium.ion@gmail.com
## Created on 02:35 Sunday May 06 2012
## C.py - 
## Produced for Google Code Jam 2012
## All rights reserved.


import sys
import itertools


def main(input):
    num_cases = int(input.pop(0))
    for case in range(1, num_cases + 1):
        total = 20
        # Construct the set.
        numbers = [int(i) for i in input.pop(0).split()][1:]
        
        combinations = [list(itertools.combinations(numbers, i)) for i in range(1, len(numbers))]
        combinations = reduce(lambda x, y: x + y, combinations)
        sums = [sum(x) for x in combinations]
        if len(set(sums)) == len(sums) :
            answer = ["Impossible"]
        else:
            for i, j in enumerate(sums):
                if sums.count(j) > 1:
                    answer = [combinations[i], combinations[sums.index(j, i+1)]]
                    break
        
        print "Case #%d:" % case
        for i in answer:
            print " ".join([str(x) for x in i])

def findSum(numbers, total):
    # Find the numbers in a set which add up to x.
    sets = set()
    
    if total == 0:
        return numbers
    elif total < 0:
        return None
    
    for i in numbers:
        fsum = findSum(set.difference(numbers, {i}), total-i)
        print fsum
        if fsum is None:
            continue
        sets.add(tuple([i] + list(x) for x in fsum))
    
    return sets
    

try:
    data = open(sys.argv[1]).read().split("\n")
except IOError:
    print "Invalid input file."
except IndexError:
    while True:
        num_statements = int(raw_input("Lines: "))
        args = ["1"]
        for i in range(num_statements):
            args.append(raw_input())
        print "Output:"
        main(args)
else:
    if len(sys.argv) > 2:
        outfile = sys.argv[2]
    else:
        outfile = ".".join(sys.argv[1].split(".")[:-1])+".out"

    sys.stdout = open(outfile, "w")
    main(data)
    sys.stdout.close()
