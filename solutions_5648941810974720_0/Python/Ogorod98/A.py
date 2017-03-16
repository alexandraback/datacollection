#!/usr/bin/python3

def solve():
    inp = input()
    letters = dict()
    for c in map(chr, range(ord('A'), ord('Z') + 1)):
        letters[c] = 0
    for c in inp:
        letters[c] += 1
    # Some magic :-)
    return  '0' * letters['Z'] + '1' * (letters['O'] - letters['Z'] - letters['W'] - letters['U']) + '2' * letters['W'] + '3' * (letters['H'] - letters['G']) + '4' * letters['U'] + '5' * (letters['F'] - letters['U']) + '6' * letters['X'] + '7' * (letters['S'] - letters['X']) + '8' * letters['G'] + '9' * (letters['I'] - letters['F'] + letters['U'] - letters['X'] - letters['G'])

n = int(input())

for i in range(n):
    print('Case #{}:'.format(i + 1), solve())
