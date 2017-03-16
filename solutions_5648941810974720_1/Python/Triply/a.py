
import string
import numpy as np

letters = string.ascii_lowercase


def word_to_vector(word):
    v = np.zeros((26,))
    for c in word:
        v[letters.index(c)] += 1
    return v


m = np.zeros((26, 10))
m[:, 0] = word_to_vector('zero')
m[:, 1] = word_to_vector('one')
m[:, 2] = word_to_vector('two')
m[:, 3] = word_to_vector('three')
m[:, 4] = word_to_vector('four')
m[:, 5] = word_to_vector('five')
m[:, 6] = word_to_vector('six')
m[:, 7] = word_to_vector('seven')
m[:, 8] = word_to_vector('eight')
m[:, 9] = word_to_vector('nine')


def find_phone_number(s):
    letter_count = np.zeros((26,))
    for c in s.lower():
        letter_count[letters.index(c)] += 1
    numbers = np.linalg.lstsq(m, letter_count)[0]
    # print numbers
    phone = ''
    for i in xrange(10):
        phone += str(i) * int(numbers[i] + 1e-6)
    return phone



# INPUT = 'A-small-attempt0.in'
# OUTPUT = 'A-small-attempt0.out'

INPUT = 'A-large.in'
OUTPUT = 'A-large.out'

# INPUT = 'A-test.in'
# OUTPUT = 'A-test.out'


with open(INPUT, 'r') as fin:
    T = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, T + 1):
            # get input
            s = fin.readline().strip()
            fout.write('Case #{}: {}\n'.format(i, find_phone_number(s)))
