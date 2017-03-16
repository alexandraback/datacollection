#!/usr/bin/env python
import sys
def read_int(): return int(sys.stdin.readline())
def read_floats(): return [float(x) for x in sys.stdin.readline().split()]

# naomi - Naomi's real hand
# deck2 - Sorted Ken's deck
def findKenIndex(naomi, deck2):
    # If Ken can win, returns the smallest of candidates.
    for i,v in enumerate(deck2):
        if naomi < v:
            return i
    # If Ken cannot win, returns the smallest.
    return 0

def findKenIndexWhenDeceitful(naomi, deck2):
    # If Naomi can win by cheating, Ken picks the smallest.
    if deck2[0] < naomi:
        return 0
    # If Naomi cannot win even if she cheats, Ken picks the largest.
    else:
        return -1  # last index

def solveWar(deck1, deck2):
    wins = 0
    deck1.sort()
    deck2.sort()
    for a in deck1:
        index = findKenIndex(a, deck2)
        if a > deck2[index]:
            wins += 1
        del deck2[index]
    return wins

def solveDeceitfulWar(deck1, deck2):
    wins = 0
    deck1.sort()
    deck2.sort()
    for a in deck1:
        index = findKenIndexWhenDeceitful(a, deck2)
        if a > deck2[index]:
            wins += 1
        del deck2[index]
    return wins

if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        N = read_int()
        deck1 = read_floats()
        deck2 = read_floats()
        ans1 = solveDeceitfulWar(deck1[:], deck2[:])
        ans2 = solveWar(deck1, deck2)
        print('Case #{}: {} {}'.format(i+1, ans1, ans2))
