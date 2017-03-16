def main():
    t = int(raw_input())  # read a line with a single integer
    for caseIdx in xrange(1, t + 1):
        S = raw_input()

        ans = solve(S)

        print "Case #{}: {}".format(caseIdx, ans)

def solve(S):
    numsCount = [0]*10
    charCount = dict()

    for c in S:
        if c in charCount:
            charCount[c] += 1
        else:
            charCount[c] = 1

    # 0
    if 'Z' in charCount:
        count = charCount['Z']
        if count > 0:
            numsCount[0] = count

            charCount['Z'] -= count
            charCount['E'] -= count
            charCount['R'] -= count
            charCount['O'] -= count

    # 2
    if 'W' in charCount:
        count = charCount['W']
        if count > 0:
            numsCount[2] = count

            charCount['T'] -= count
            charCount['W'] -= count
            charCount['O'] -= count

    # 4
    if 'U' in charCount:
        count = charCount['U']
        if count > 0:
            numsCount[4] = count

            charCount['F'] -= count
            charCount['O'] -= count
            charCount['U'] -= count
            charCount['R'] -= count

    # 6
    if 'X' in charCount:
        count = charCount['X']
        if count > 0:
            numsCount[6] = count

            charCount['S'] -= count
            charCount['I'] -= count
            charCount['X'] -= count

    # ===

    # 5
    if 'F' in charCount:
        count = charCount['F']
        if count > 0:
            numsCount[5] = count

            charCount['F'] -= count
            charCount['I'] -= count
            charCount['V'] -= count
            charCount['E'] -= count

    if 'G' in charCount:
        count = charCount['G']
        if count > 0:
            numsCount[8] = count

            charCount['E'] -= count
            charCount['I'] -= count
            charCount['G'] -= count
            charCount['H'] -= count
            charCount['T'] -= count

    if 'O' in charCount:
        count = charCount['O']
        if count > 0:
            numsCount[1] = count

            charCount['O'] -= count
            charCount['N'] -= count
            charCount['E'] -= count

    if 'R' in charCount:
        count = charCount['R']
        if count > 0:
            numsCount[3] = count

            charCount['T'] -= count
            charCount['H'] -= count
            charCount['R'] -= count
            charCount['E'] -= count
            charCount['E'] -= count

    if 'S' in charCount:
        count = charCount['S']
        if count > 0:
            numsCount[7] = count

            charCount['S'] -= count
            charCount['E'] -= count
            charCount['V'] -= count
            charCount['E'] -= count
            charCount['N'] -= count

    if 'E' in charCount:
        count = charCount['E']
        if count > 0:
            numsCount[9] = count

            charCount['N'] -= count
            charCount['I'] -= count
            charCount['N'] -= count
            charCount['E'] -= count

    ans = ""
    for num in xrange(len(numsCount)):
        count = numsCount[num]
        ans += str(num)*count

    return ans


if __name__ == '__main__':
    main()
