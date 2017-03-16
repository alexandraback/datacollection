from itertools import product
import re

def solve(K, L, S, keyboards, target):
    """ solve the problem """

    #print(K, L, S, keyboards, target)
    for letter in target:
        if letter not in keyboards: return 0.0

    target_left = target[:]
    target_right = target[:]
    overlap = ''
    overlap_count = 0
    while True:
        if len(target_left) == 0: break
        target_left = target_left[1:]
        target_right = target_right[:-1]
        if target_left == target_right: 
            overlap = target_left[:]
            overlap_count = len(overlap)
            break
    to_bring = int((S - L)/(L-overlap_count)) + 1

    letters = dict()
    for l in keyboards:
        if l in letters:
            letters[l] += 1
        else:
            letters[l] = 1

    for k, v in letters.items():
        letters[k] /= K

    woo = S - (L-1)

    p = 1.0
    for l in target:
        p *= letters[l]

    ans = to_bring - p * woo

    return ans


def parse():
    """ parse input """

    K, L, S = [int(i) for i in input().split()]
    keyboards = input()
    target = input()

    return K, L, S, keyboards, target


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
