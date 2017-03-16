# -*- coding: utf-8 -*-
"""
@author: Ivan Koblik
"""

import sys

if len(sys.argv) <= 1:
    print "Expected input file name"
    exit(0)

def read_cases(from_file):
    with open(from_file) as f:
        lines = f.readlines()
    num_samples = int(lines[0])
    result = []
    current_row = 1
    for i in range(num_samples):
        name,nvalue = lines[current_row].split(" ")
        nvalue = int(nvalue)
        result.append((name, nvalue))        
        current_row += 1
    return result

vowels = {"a", "e", "i", "o", "u"}

def countNValue(name, n):
    nvalue = 0
    cutoff = 0
    start = 0
    end = 0
    l = len(name)
    while(end < l):
        if name[end] in vowels:
            start = end+1
        if (end - start + 1 >= n):
            oldcutoff = cutoff
            cutoff = end - n + 2 #past index of start
            prefix = end - n + 1 - oldcutoff
            suffix = l - end - 1
            nvalue +=  (prefix+1) * (suffix+1)
        end += 1
    return nvalue
    

names = read_cases(sys.argv[1])
for i in range(len(names)):
    name,nvalue = names[i]
    print "Case #" + str(i+1) + ": " + str(countNValue(name, nvalue))
