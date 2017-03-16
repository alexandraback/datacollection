#!/usr/bin/env python

from sys import argv

script, filename = argv

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        lookup = { 0: 0 }
        N = int(f.readline().rstrip('\n'))
        for i in range(1, 2 * N):
            line = f.readline().rstrip('\n')
            soldiers = line.split(' ')
            for j in range(0, N):
                dude = soldiers[j]
                lookup[dude] = 1 - lookup.get(dude, 0)

        answer = []
        for key, value in sorted(lookup.iteritems()):
            if value > 0:
                answer.append(key)
        answer.sort(key=int)
        print "Case #{}: {}".format(case_number, ' '.join(answer))
