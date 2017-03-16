'''
cat a_test.in | python problem_a.py
cat A-small-attempt0.in | python problem_a.py >A-small.out
cat A-large.in | python problem_a.py >A-large.out
'''

from collections import Counter
import sys

def dec(c, s, count):
    for ch in s:
        c[ch] -= count
    return count

def main():
    t = int(sys.stdin.readline().strip())
    for k in xrange(t):
        s = sys.stdin.readline().strip()
        char_counts = Counter()
        for ch in s:
            char_counts[ch] += 1
        digit_counts = Counter()
        digit_counts[0] = dec(char_counts, 'ZERO', char_counts['Z'])
        digit_counts[2] = dec(char_counts, 'TWO', char_counts['W'])
        digit_counts[6] = dec(char_counts, 'SIX', char_counts['X'])
        digit_counts[4] = dec(char_counts, 'FOUR', char_counts['U'])
        digit_counts[7] = dec(char_counts, 'SEVEN', char_counts['S'])
        digit_counts[5] = dec(char_counts, 'FIVE', char_counts['V'])
        digit_counts[1] = dec(char_counts, 'ONE', char_counts['O'])
        digit_counts[8] = dec(char_counts, 'EIGHT', char_counts['G'])
        digit_counts[3] = dec(char_counts, 'THREE', char_counts['H'])
        digit_counts[9] = dec(char_counts, 'NINE', char_counts['E'])
        print "Case #{}: {}".format(k+1, "".join(str(v)*digit_counts[v] for v in xrange(10)))

main()
