import sys
import math
from collections import Counter

def test():
    # For each size of pancake pile, how many moves would it take
    # to get down to that many pancakes remaining?
    sys.stdin.readline()
    nums = map(int, sys.stdin.readline().strip().split())
    # cakeCounts is a list of (n, l) for l piles of n cakes high
    cakeCounts = Counter(nums)

    minMoves = None

    maxSize = max(cakeCounts.keys())
    for i in range(1, maxSize+1):
        moves = 0
        # How many moves to get down to all piles <= i?
        for count, piles in cakeCounts.items():
            # Already under size!
            if count < i: continue
            # We would need this many...
            moves += (math.ceil(count/i) - 1) * piles
        # And this many to eat a pancake pile size i
        moves += i
        minMoves = min(moves, minMoves) if minMoves is not None else moves

    return minMoves

def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = test()
        print('Case #{}: {}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)

