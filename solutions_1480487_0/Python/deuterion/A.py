#! /usr/bin/env python

## Written by Joey Tuong- deuterium.ion@gmail.com
## Created on 01:53 Sunday May 06 2012
## A.py - 
## Produced for Google Code Jam 2012
## All rights reserved.


import sys


def main(input):
    num_cases = int(input.pop(0))
    for case in range(1, num_cases + 1):
        data = input.pop(0).split();
        num_contestants = int(data.pop(0))
        points = [int(i) for i in data]
        X = float(sum(points))
        min_required = 2.0 * X / num_contestants 
        needed = [(min_required - i)/X for i in points]

        while len([i for i in needed if i>=0]) != len(needed) and len([i for i in needed if i>=0]) != num_contestants:
            num_contestants = len([i for i in needed if i>=0])
            min_required = 2.0 * X / num_contestants 

            needed = [(min_required - i)/X for i in points]
        
        if [i for i in needed if i<0]:
            needed = [i if i>=0 else 0 for i in needed]
        
        total = sum(needed)
        
        needed = [i/total for i in needed]
        
        
        answer = " ".join([repr(100*x) for x in needed])
        
        print "Case #%d: %s" % (case, answer)


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
