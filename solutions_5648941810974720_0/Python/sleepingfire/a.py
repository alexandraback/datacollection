import sys, os

def main(s):
    nums = []
    cnts = {}
    for c in s:
        if c not in cnts:
            cnts[c] = 1
        else:
            cnts[c] += 1

    # ZERO
    if 'Z' in cnts:
        cnt = cnts['Z']
        for i in range(cnt):
            nums.append(0)
        cnts['E'] -= cnt
        cnts['R'] -= cnt
        cnts['O'] -= cnt
        del cnts['Z']

    # TWO
    if 'W' in cnts:
        cnt = cnts['W']
        for i in range(cnt):
            nums.append(2)
        cnts['T'] -= cnt
        cnts['O'] -= cnt
        del cnts['W']

    # FOUR
    if 'U' in cnts:
        cnt = cnts['U']
        for i in range(cnt):
            nums.append(4)
        cnts['F'] -= cnt
        cnts['O'] -= cnt
        cnts['R'] -= cnt
        del cnts['U']

    # SIX
    if 'X' in cnts:
        cnt = cnts['X']
        for i in range(cnt):
            nums.append(6)
        cnts['S'] -= cnt
        cnts['I'] -= cnt
        del cnts['X']

    # EIGHT
    if 'G' in cnts:
        cnt = cnts['G']
        for i in range(cnt):
            nums.append(8)
        cnts['E'] -= cnt
        cnts['I'] -= cnt
        cnts['H'] -= cnt
        cnts['T'] -= cnt
        del cnts['G']

    # ONE
    if 'O' in cnts and cnts['O'] > 0:
        cnt = cnts['O']
        for i in range(cnt):
            nums.append(1)
        cnts['N'] -= cnt
        cnts['E'] -= cnt
        del cnts['O']

    # THREE
    if 'T' in cnts and cnts['T'] > 0:
        cnt = cnts['T']
        for i in range(cnt):
            nums.append(3)
        cnts['H'] -= cnt
        cnts['R'] -= cnt
        cnts['E'] -= cnt * 2
        del cnts['T']

    # FIVE
    if 'F' in cnts and cnts['F'] > 0:
        cnt = cnts['F']
        for i in range(cnt):
            nums.append(5)
        cnts['I'] -= cnt
        cnts['V'] -= cnt
        cnts['E'] -= cnt
        del cnts['F']

    # SEVEN
    if 'S' in cnts and cnts['S'] > 0:
        cnt = cnts['S']
        for i in range(cnt):
            nums.append(7)
        cnts['E'] -= cnt * 2
        cnts['V'] -= cnt
        cnts['N'] -= cnt
        del cnts['S']

    # NINE
    if 'I' in cnts and cnts['I'] > 0:
        cnt = cnts['I']
        for i in range(cnt):
            nums.append(9)
        cnts['N'] -= cnt * 2
        cnts['E'] -= cnt
        del cnts['I']

    nums.sort()
    return ''.join([str(c) for c in nums])


if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        s = in_file.readline().rstrip()
        res = main(s)
        print("Case #{}: {}".format(case_idx + 1, res))
