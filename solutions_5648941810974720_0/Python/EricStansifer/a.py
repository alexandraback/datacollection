# Python 3.5

from common import *

# "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

def main(casenum):
    s = readline()
    counts = [0] * 10
    chars = {}
    # chars['Z'] = 0 # ZERO
    # chars['W'] = 0 # TWO
    # chars['X'] = 0 # SIX
    # chars['S'] = 0 # SEVEN
    # chars['V'] = 0 # FIVE
    # chars['F'] = 0 # FOUR
    # chars['G'] = 0 # EIGHT
    # chars['I'] = 0 # NINE
    # chars['R'] = 0 # THREE
    # chars['O'] = 0 # ONE
    for c in "ZEROONETWOTHREEFOURFIVESIXSEVENEIGHTNINE":
        chars[c] = 0

    for c in s:
        chars[c] += 1

    a = counts[0] = chars['Z']
    chars['Z'] -= a
    chars['E'] -= a
    chars['R'] -= a
    chars['O'] -= a

    a = counts[2] = chars['W']
    chars['T'] -= a
    chars['W'] -= a
    chars['O'] -= a

    a = counts[6] = chars['X']
    chars['S'] -= a
    chars['I'] -= a
    chars['X'] -= a

    a = counts[7] = chars['S']
    chars['S'] -= a
    chars['E'] -= a
    chars['V'] -= a
    chars['E'] -= a
    chars['N'] -= a

    a = counts[5] = chars['V']
    chars['F'] -= a
    chars['I'] -= a
    chars['V'] -= a
    chars['E'] -= a

    a = counts[4] = chars['F']
    chars['F'] -= a
    chars['O'] -= a
    chars['U'] -= a
    chars['R'] -= a

    a = counts[8] = chars['G']
    chars['E'] -= a
    chars['I'] -= a
    chars['G'] -= a
    chars['H'] -= a
    chars['T'] -= a

    a = counts[9] = chars['I']
    chars['N'] -= a
    chars['I'] -= a
    chars['N'] -= a
    chars['E'] -= a

    a = counts[3] = chars['R']
    chars['T'] -= a
    chars['H'] -= a
    chars['R'] -= a
    chars['E'] -= a
    chars['E'] -= a

    a = counts[1] = chars['O']
    chars['O'] -= a
    chars['N'] -= a
    chars['E'] -= a

    out = ''
    for i in range(10):
        for j in range(counts[i]):
            out += str(i)

    writecase(casenum, out)

run(main)
