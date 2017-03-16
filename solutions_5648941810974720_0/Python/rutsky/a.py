# A
import sys
import collections

#sys.stdin = open("small.in", "rt")
#sys.stdout = open("small.out", "wt")
sys.stdin = open("A-small-attempt0.in", "rt")
sys.stdout = open("A-small-attempt0.out", "wt")
#sys.stdin = open("A-large-practice.in", "rt")
#sys.stdout = open("A-large-practice.out", "wt")


def solve(S):
    count = collections.defaultdict(int)
    for ch in S:
        count[ch] += 1

    num_digits = [0] * 10

    num_digits[6] = count['X']
    count['I'] -= count['X']
    count['S'] -= count['X']
    count['X'] = 0

    num_digits[7] = count['S']
    count['E'] -= 2 * count['S']
    count['V'] -= count['S']
    count['N'] -= count['S']
    count['S'] = 0

    num_digits[8] = count['G']
    count['E'] -= count['G']
    count['I'] -= count['G']
    count['H'] -= count['G']
    count['T'] -= count['G']
    count['G'] = 0

    num_digits[3] = count['H']
    count['T'] -= count['H']
    count['R'] -= count['H']
    count['E'] -= 2 * count['H']
    count['H'] = 0

    num_digits[4] = count['U']
    count['F'] -= count['U']
    count['O'] -= count['U']
    count['R'] -= count['U']
    count['U'] = 0

    num_digits[5] = count['V']
    count['F'] -= count['V']
    count['I'] -= count['V']
    count['E'] -= count['V']
    count['V'] = 0

    num_digits[2] = count['W']
    count['T'] -= count['W']
    count['O'] -= count['W']
    count['W'] = 0

    num_digits[0] = count['R']
    count['Z'] -= count['R']
    count['E'] -= count['R']
    count['O'] -= count['R']
    count['R'] = 0

    num_digits[9] = count['I']
    count['N'] -= 2 * count['I']
    count['E'] -= count['I']
    count['I'] = 0

    num_digits[1] = count['O']
    count['N'] -= count['O']
    count['E'] -= count['O']
    count['O'] = 0

    assert all(v == 0for v in count.values())

    res = "".join([str(d) * c for d, c in enumerate(num_digits)])

    return res

cases = int(input())
for case_idx in range(cases):
    S = input()
    print("Case #{}: {}".format(case_idx + 1, solve(S)))
