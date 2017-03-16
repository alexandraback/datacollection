"""
Therefore:

Brat will always move the ship to make you miss if possible; once the
ship is hit, it's stuck attached to that cell.


"""
from __future__ import division
from __future__ import print_function

import operator
import re
import sys

from collections import Counter
from functools import reduce
from itertools import product
from itertools import zip_longest


def grouper(iterable, n, fillvalue=None):
    "Collect data into fixed-length chunks or blocks"
    # grouper('ABCDEFG', 3, 'x') --> ABC DEF Gxx"
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)


def get_input():
    sys.stdin.readline()  # num cases

    for KLS, kb, word in grouper(sys.stdin, 3):
        K, L, S = (int(i) for i in KLS.split())
        yield (K, L, S, kb.strip(), word.strip())


def count_occurences(s, sub_s):
    return len([_ for _ in re.finditer('(?=%s)' % sub_s, s)])


def gen_all_words(kb, S):
    kb = ''.join(set(kb))
    for chars in product(kb, repeat=S):
        yield ''.join(chars)


def word_prob(word, kb_probs):
    return reduce(operator.mul, (kb_probs[c] for c in word), 1)


def solve(cases):
    for K, L, S, kb, word in cases:
        assert 1 <= K <= 7
        assert 1 <= L <= S <= 7
        assert len(kb) == K
        assert len(word) == L

        kb_freqs = Counter(kb)
        kb_probs = {char: (freq / K) for char, freq in kb_freqs.items()}

        total = 0
        top = -1
        for possible_string in gen_all_words(kb, S):
            pos_word_occurences = count_occurences(possible_string, word)

            top = max(top, pos_word_occurences)

            if pos_word_occurences:
                pos_word_prob = word_prob(possible_string, kb_probs)

                total += pos_word_occurences * pos_word_prob

        yield top - total


def main():
    cases = get_input()
    answers = solve(cases)

    for case_num, a in enumerate(answers, 1):
        print('Case #%d: %.7f' % (case_num, a))


if __name__ == '__main__':
    main()
