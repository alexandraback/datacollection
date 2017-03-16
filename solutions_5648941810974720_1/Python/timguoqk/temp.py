# https://code.google.com/codejam/contest/11254486/dashboard
from collections import Counter
from copy import copy


filein = open('20161BA.in', 'r')
fileout = open('20161BA_2.out', 'w')

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

    num_count = dict()
    num_count[0] = letters_dict['Z']
    num_count[2] = letters_dict['W']
    num_count[6] = letters_dict['X']
    num_count[8] = letters_dict['G']
    num_count[3] = letters_dict['H'] - num_count[8]
    num_count[4] = letters_dict['R'] - num_count[0] - num_count[3]
    num_count[1] = letters_dict['O'] - num_count[0] - num_count[2] - num_count[4]
    num_count[5] = letters_dict['F'] - num_count[4]
    num_count[7] = letters_dict['V'] - num_count[5]
    num_count[9] = letters_dict['I'] - num_count[5] - num_count[6] - num_count[8]

    ans = ''
    for i in range(10):
        ans += str(i) * num_count[i]
    fileout.write(ans + '\n')

filein.close()
fileout.close()
