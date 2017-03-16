#!/usr/bin/python3
from string import ascii_uppercase as ALPHA

for t in range(int(input())):
    s = input()

    frq = {x: s.count(x) for x in ALPHA}
    qty = {x: 0 for x in range(10)}

    qty[0] = frq['Z']

    frq['Z'] -= qty[0]
    frq['E'] -= qty[0]
    frq['R'] -= qty[0]
    frq['O'] -= qty[0]

    qty[2] = frq['W']

    frq['T'] -= qty[2]
    frq['W'] -= qty[2]
    frq['O'] -= qty[2]

    qty[6] = frq['X']

    frq['S'] -= qty[6]
    frq['I'] -= qty[6]
    frq['X'] -= qty[6]

    qty[7] = frq['S']

    frq['S'] -= qty[7]
    frq['E'] -= 2*qty[7]
    frq['V'] -= qty[7]
    frq['N'] -= qty[7]

    qty[5] = frq['V']

    frq['F'] -= qty[5]
    frq['I'] -= qty[5]
    frq['V'] -= qty[5]
    frq['E'] -= qty[5]

    qty[4] = frq['F']

    frq['F'] -= qty[4]
    frq['O'] -= qty[4]
    frq['U'] -= qty[4]
    frq['R'] -= qty[4]

    qty[1] = frq['O']

    frq['O'] -= qty[1]
    frq['N'] -= qty[1]
    frq['E'] -= qty[1]

    qty[3] = frq['R']

    frq['T'] -= qty[3]
    frq['H'] -= qty[3]
    frq['R'] -= qty[3]
    frq['E'] -= 2*qty[3]

    qty[8] = frq['G']
    qty[9] = frq['N'] // 2

    print("Case #%i: " % (t+1), end='')
    for digit in range(10):
        print("%s" % ''.join([str(digit) * qty[digit]]), end='')
    print()
