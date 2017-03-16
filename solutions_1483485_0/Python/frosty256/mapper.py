#!/usr/bin/python

import re
from string import letters, lower, upper
from sys import argv
from collections import defaultdict

letters = re.sub('[A-Z]', '', letters)

casere = re.compile('[\s]*Case\s\#[0-9]*:[\s]*')
formatter = lambda x: re.sub(casere, '', x)

input_training = [
        'ejp mysljylc kd kxveddknmc re jsicpdrysi',
        'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
        'de kr kd eoya kw aej tysr re ujdr lkgc jv',
]

output_training = [
        'Case #1: our language is impossible to understand',
        'Case #2: there are twenty six factorial possibilities',
        'Case #3: so it is okay if you want to just give up',
]

input_training = ''.join(input_training)
output_training = ''.join(map(formatter, output_training))

charmap = defaultdict(str)
for i, o in zip(input_training, output_training):
    charmap[lower(i)] = lower(o)
    charmap[upper(i)] = upper(o)

skeys = set(charmap.keys())
svals = set(charmap.values())
salpha = set([c for c in letters])

#
#last_key = ''.join(salpha.difference(skeys))
#last_val = ''.join(salpha.difference(skeys))
#
#print last_val, last_key
#if len(last_val) == 1 and len(last_key) == 1:
#    charmap[last_key] = last_val
#
#print len(charmap)

charmap['z'] = 'q'
charmap['q'] = 'z'

inputf = open(argv[1], 'r')
outputf = open('results.txt', 'w')

input_buffer = inputf.readlines()[1:]
outputbuffer = []

for i, line in enumerate(input_buffer, start = 1):
    outputbuffer.append('Case #{0}: '.format(i) + ''.join([charmap[c] for c in line]) + '\n')

outputf.writelines(outputbuffer)
