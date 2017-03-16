# https://code.google.com/codejam/contest/11254486/dashboard
from collections import Counter
from copy import copy


filein = open('20161BA.in', 'r')
fileout = open('20161BA.out', 'w')

T = int(filein.readline())

candidates = [
    ("ZERO", (0, {'Z': 1, 'E': 1, 'R': 1, 'O': 1})),
    ("ONE", (1, {'O': 1, 'N': 1, 'E': 1})),
    ("TWO", (2, {'T': 1, 'W': 1, 'O': 1})),
    ("THREE", (3, {'T': 1, 'H': 1, 'R': 1, 'E': 2})),
    ("FOUR", (4, {'F': 1, 'O': 1, 'U': 1, 'R': 1})),
    ("FIVE", (5, {'F': 1, 'I': 1, 'V': 1, 'E': 1})),
    ("SIX", (6, {'S': 1, 'I': 1, 'X': 1})),
    ("SEVEN", (7, {'S': 1, 'E': 2, 'V': 1, 'N': 1})),
    ("EIGHT", (8, {'E': 1, 'I': 1, 'G': 1, 'H': 1, 'T': 1})),
    ("NINE", (9, {'N': 2, 'I': 1, 'E': 1}))
]

for t in range(T):
    fileout.write('Case #%d: ' % (t + 1))

    letters_dict = dict(Counter(filein.readline().strip()))
    for k in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        if k not in letters_dict:
            letters_dict[k] = 0

    def solve(prefix, curr_num, available_dict):
        if all(available_dict[k] == 0 for k in available_dict.keys()):
            return prefix
        if curr_num == 10:
            return ''

        curr_num_dict = candidates[curr_num][1][1]
        max_repeat = min(
            int(available_dict[k] / curr_num_dict[k])
            for k in curr_num_dict.keys())
        for i in range(max_repeat + 1):
            new_dict = copy(available_dict)
            for letter, count in curr_num_dict.items():
                new_dict[letter] -= i * count
            ans = solve(prefix + str(curr_num) * i, curr_num + 1, new_dict)
            if ans != '':
                return ans
        return ''
    res = solve('', 0, letters_dict)
    fileout.write(res + '\n')

filein.close()
fileout.close()
