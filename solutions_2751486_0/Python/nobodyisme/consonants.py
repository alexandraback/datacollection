import itertools
from math import factorial
import sys

input_fname = sys.argv[1]
input_f = open(input_fname)

output_fname = sys.argv[2]
output_f = open(output_fname, 'w')


VOWELS = 'aeiou'

def test_cases(input_f):
    return input_f.readline()


def parse_test_case(input_f):
    _word, _n = [x for x in input_f.readline().split(' ')]
    _n = int(_n)
    return (_word, _n)


def process_test_case(test_case):
    _word, _n = test_case

    cons_parts = []

    word_len = len(_word)

    i = 0
    for i in xrange(len(_word) - _n + 1):
        part =  _word[i:i + _n]

        is_cons_part = True
        for c in part:
            if c in VOWELS:
                is_cons_part = False
                break
        else:
            cons_parts.append((part, i, i + _n, len(cons_parts) ))

    print cons_parts

    comb_sum = 0

    for comb in itertools.combinations(cons_parts, 1):

        min_left = comb[0][1]
        max_right = comb[-1][2]

        local_comb_num = (min_left + 1) * (word_len - max_right + 1)
        comb_sum += local_comb_num

    for i in xrange(1, len(cons_parts)):
        els_in_comb = i + 1
        print "Processing", els_in_comb, "combinations"
        for comb in itertools.combinations(cons_parts, 2):

            min_left = comb[0][1]
            max_right = comb[-1][2]
            distance = comb[-1][3] - comb[0][3]

            if distance < els_in_comb - 1:
                continue

            places = distance - 1
            free_els = els_in_comb - 2
            variations = factorial(places) / ( factorial(free_els) * factorial(places - free_els) )

            # min_left = min([x[1] for x in comb])
            # max_right = max([x[2] for x in comb])

            local_comb_num = (min_left + 1) * (word_len - max_right + 1) * variations
            if i % 2 == 0:
                comb_sum += local_comb_num
            else:
                comb_sum -= local_comb_num

    return comb_sum



for icase in xrange(int(test_cases(input_f))):
    test_case = parse_test_case(input_f)
    # for line in test_case:
    #     print line
    print "Processing test case", icase + 1
    res = process_test_case(test_case)
    output_f.write('Case #{0}: {1}\n'.format(icase + 1, res))


output_f.flush()
output_f.close()
