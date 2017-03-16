#!/usr/bin/python

import sys

def follow(classes, index, seen):
    if index + 1 in seen:
        return True
    seen.add(index + 1)
    for clazz in classes[index]:
        if follow(classes, clazz - 1, seen):
            return True
    return False

def solve(case):
    num_classes = case[0][0]
    classes = [line[1:] for line in case[1:]]
    for i in range(num_classes):
        if follow(classes, i, set()):
            return 'Yes'
    return 'No'

input = [map(int, line.strip().split()) for line in sys.stdin]
counter = 0
line = 1
while counter < input[0][0]:
    counter += 1
    num_classes = input[line][0]
    case = input[line : line + 1 + num_classes]
    print 'Case #%d: %s' % (counter, solve(case))
    line += num_classes + 1
