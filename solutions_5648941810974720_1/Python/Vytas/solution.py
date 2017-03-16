import time
import sys

SAMPLE = """4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER"""


class Problem(object):
    """
    A simple helper class for parsing Google Code Jam problem inputs and
    formatting solutions.

    (C) Vytautas Liuolia 2016
    """

    def __init__(self):
        self.cases = []

    def parse_case(self, lines):
        raise NotImplementedError

    def solve(self, case):
        raise NotImplementedError

    def read_cases(self, lines=None):
        if lines is None:
            lines = (line.strip() for line in sys.stdin)
        amount = int(lines.next())
        for index in xrange(amount):
            self.cases.append(self.parse_case(lines))

    def print_report(self, verbose=False):
        for index, case in enumerate(self.cases):
            start = time.time()
            result = self.solve(case)
            elapsed = time.time() - start
            if verbose:
                print "Solved case {0} in  {1} s".format(case, elapsed)
            print "Case #{0}: {1}".format(index + 1, result)
            if verbose:
                print ''

    @classmethod
    def run(cls):
        task = cls()
        task.read_cases()
        task.print_report()

    @classmethod
    def run_sample(cls, data):
        if isinstance(data, basestring):
            data = data.splitlines()
        task = cls()
        task.read_cases(iter(data))
        task.print_report(verbose=True)


def letter_counts(word):
    counts = {}
    for letter in word:
        counts[letter] = counts.get(letter, 0) + 1
    return counts


def unique_chain(words):
    if not words:
        return []
    for word in words:
        for letter in word:
            if not any(letter in other for other in words
                       if other != word):
                result = [word]
                return result + unique_chain(words - set(result))


DIGITS = ('ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN',
          'EIGHT', 'NINE')
DIGIT_TRANS = {word: digit for digit, word in enumerate(DIGITS)}
DIGIT_COUNTS = {digit: letter_counts(word)
                for digit, word in enumerate(DIGITS)}
UNIQUE_CHAIN = [DIGIT_TRANS[word] for word in unique_chain(set(DIGITS))]


class Solution(Problem):

    def solve(self, case):
        counts = letter_counts(case)
        found = []

        for digit in UNIQUE_CHAIN:
            while all(counts.get(letter, 0) >= count
                      for letter, count in DIGIT_COUNTS[digit].items()):
                found.append(digit)
                for letter, count in DIGIT_COUNTS[digit].items():
                    counts[letter] -= count

        return ''.join(map(str, sorted(found)))

    def parse_case(self, lines):
        return lines.next().strip()


if __name__ == '__main__':
    # Solution.run_sample(SAMPLE)
    Solution.run()
