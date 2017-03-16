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
        ours, N = map(int, lines[current_row].split(" "))
        others = map(int, lines[current_row+1].split(" "))
        assert(len(others) == N)
        others.insert(0, ours)
        result.append(others)
        current_row += 2
    return result

def count_moves(our, others):
    others.sort()
    added = [0 for i in others]
    curr_size = our
    to_stop = len(others)
    for i in xrange(len(others)):
        other = others[i]
        if curr_size > other:
            curr_size += other
            continue
        else:
            num_added = 0
            remaining = len(others) - i
            temp_size = curr_size
            for j in xrange(remaining):
                temp_size = temp_size*2 - 1
                if temp_size > other:
                    num_added = j+1
                    break
            if num_added > 0:
                curr_size = temp_size + other
                added[i] = num_added
                continue
            else:
                to_stop = i
                break
    #print our, others, added, curr_size, to_stop
    counts = [0 for i in range(to_stop)]
    count = sum(added) + len(others) - to_stop
    for i in xrange(to_stop-1, -1, -1):
        if added[i] == 0:
            counts[i] = count
            count = count + 1 # will need to remove 1 item in future
            continue
        for j in range(added[i]):
            curr_size = (curr_size + 1)/2
        count = count - added[i] + 1 #no need to add, but need to remove this node
        counts[i] = count
    return len(others) if len(counts) == 0 else min(counts)

fields = read_cases(sys.argv[1])
for i in range(len(fields)):
    field = fields[i]
    our = field[0]
    others = field[1:]
    print "Case #" + str(i+1) + ": " + str(count_moves(our, others))
