#! /usr/bin/env python3

import sys

def solve(numbers):
    counts = dict((n, 0) for n in set(numbers))
    for n in numbers:
        counts[n] += 1
    row = list()
    for (n, c) in counts.items():
        if c % 2 == 1:
            row.append(n)
    return ' '.join(map(str, sorted(row))) 

#################################################################

if __name__ == '__main__':
    filename = sys.argv[1]

    with open(filename) as f:
        content = f.read().strip()

    numbers = list(map(int, content.split()))
    T = numbers[0]
    numbers = numbers[1:]

    for c in range(T):
        N = numbers[0]
        numbers = numbers[1:]
        ns = (2*N - 1)*N
        lists = numbers[:ns]
        numbers = numbers[ns:]
        print('Case #', c+1, ': ', solve(lists), sep='')
