# Solution to "Getting the Digits" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys
from collections import Counter

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield f.readline().rstrip('\n')

table = [(0, 'Z', 'ZERO'),
         (2, 'W', 'TWO'),
         (4, 'U', 'FOUR'),
         (6, 'X', 'SIX'),
         (8, 'G', 'EIGHT'),
         (3, 'T', 'THREE'),
         (5, 'F', 'FIVE'),
         (7, 'V', 'SEVEN'),
         (9, 'I', 'NINE'),
         (1, 'O', 'ONE')]

def solve(digits):
    results = [0 for x in range(10)]
    counts = Counter(digits)
    for digit, test, string in table:
        digitCount = counts[test]
        for letter in string:
            counts[letter] -= digitCount
        results[digit] += digitCount
    return ''.join(count*str(digit) for digit, count in enumerate(results))

with open(sys.argv[2], 'w') as f:
    for num, digits in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %s\n"%(num+1, solve(digits)))
