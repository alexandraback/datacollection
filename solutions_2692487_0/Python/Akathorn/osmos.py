#!/usr/bin/python
# -*- coding:utf-8 -*-

import sys
import numpy as np

def get_ints(input_data):
    return map(lambda x: int(x), input_data.pop(0).strip().split(" "))

def motes_to_eat(armin, mote):
    count = 0
    while armin <= mote:
        armin += (armin-1)
        count += 1

    return (count, armin)

def solve(motes, armin):
    n_motes = len(motes)

    i = 0
    while i < n_motes and motes[i] < armin:
        armin += motes[i]
        i+=1

    if i < n_motes:
        if armin > 1:
            # Grow up
            (count, newArmin) = motes_to_eat(armin, motes[i])
            grow_steps = solve(motes[i:], newArmin) + count

            # Remove
            remove_steps = solve(motes[i+1:], armin) + 1

            return min(grow_steps, remove_steps)
        else:
            return n_motes
    else:
        return 0



if __name__ == "__main__":
    input_data = [line for line in sys.stdin.readlines()]

    [num_tests] = get_ints(input_data)

    for i in range(0,num_tests):
        [A, N] = get_ints(input_data)
        motes  = np.array(get_ints(input_data))
        motes.sort()

        print "Case #%d: %d" % (i+1, solve(motes, A))
