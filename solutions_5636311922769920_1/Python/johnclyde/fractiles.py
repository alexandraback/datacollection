#!/usr/bin/env python

from sys import argv

script, filename = argv

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        K, C, S = f.readline().rstrip('\n').split()
        length = 0
        num_tiles = pow(int(K), int(C))
        sequence = ['1']
        for i in range(1, int(K)):
            spacing = (num_tiles - 1) / (int(K) - 1)
            sequence.append('{}'.format(1 + spacing * i))
        print "Case #{}: {}".format(case_number, ' '.join(sequence) if S == K else 'IMPOSSIBLE')
