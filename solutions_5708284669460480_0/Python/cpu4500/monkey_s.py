#!/usr/bin/python

import sys
import itertools

def add_key(string, keys, last_pos):
    string += keys[last_pos+1]

lines = open(sys.argv[1], "rt").readlines()

test_cases_c = int(lines[0])

lines = lines[1:]

for i in xrange(test_cases_c):
    print "Case #"+str(i+1)+":",
    case_params = lines[0].strip()
    keys_c, word_length, type_length = case_params.split()
    keys_c = int(keys_c)
    word_length = int(word_length)
    type_length = int(type_length)
    keys = lines[1].strip()
    word = lines[2].strip()

    if len(lines) > 3:
        lines = lines[3:]

    options = range(keys_c)

    max_count = 0
    total_count = 0
    num_options = 0
    for sol in itertools.product(options, repeat=type_length):
        num_options += 1
        string = ""
        for j in sol:
            string += keys[j]
        count = 0
        for j in xrange(len(string)):
            if len(string) - j < word_length:
                break
            sub = string[j:j+word_length]
            if sub == word:
                total_count += 1
                count += 1
        if count > max_count:
            max_count = count
    ans = max_count - (float(total_count) / float(num_options))

    print str(ans)
