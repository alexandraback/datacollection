inputF = open('A-small-attempt0.in', 'r')
output = open('A-small-attempt0.out', 'w')


def removeLetters(digitLetters):
    # Order: *Z*ERO, SI*X*, EI*G*HT, T*W*O, FO*U*R, *F*IVE, *T*HREE, N*I*NE,
    #         *O*NE, *SEVEN
    letterCounts = {}
    for letter in digitLetters:
        if letter in letterCounts:
            letterCounts[letter] += 1
        else:
            letterCounts[letter] = 1

    counts = {}
    #*Z*ERO
    if 'Z' in letterCounts and letterCounts['Z'] != 0:
        x = letterCounts['Z']
        counts[0] = x
        letterCounts['Z'] -= x
        letterCounts['E'] -= x
        letterCounts['R'] -= x
        letterCounts['O'] -= x
    # SIX
    if 'X' in letterCounts and letterCounts['X'] != 0:
        x = letterCounts['X']
        counts[6] = x
        letterCounts['S'] -= x
        letterCounts['I'] -= x
        letterCounts['X'] -= x
    #EIGHT
    if 'G' in letterCounts and letterCounts['G'] != 0:
        x = letterCounts['G']
        counts[8] = x
        letterCounts['E'] -= x
        letterCounts['I'] -= x
        letterCounts['G'] -= x
        letterCounts['H'] -= x
        letterCounts['T'] -= x
    #TWO
    if 'W' in letterCounts and letterCounts['W'] != 0:
        x = letterCounts['W']
        counts[2] = x
        letterCounts['T'] -= x
        letterCounts['W'] -= x
        letterCounts['O'] -= x
    #FOUR
    if 'U' in letterCounts and letterCounts['U'] != 0:
        x = letterCounts['U']
        counts[4] = x
        letterCounts['F'] -= x
        letterCounts['O'] -= x
        letterCounts['U'] -= x
        letterCounts['R'] -= x
    #FIVE
    if 'F' in letterCounts and letterCounts['F'] != 0:
        x = letterCounts['F']
        counts[5] = x
        letterCounts['F'] -= x
        letterCounts['I'] -= x
        letterCounts['V'] -= x
        letterCounts['E'] -= x
    #THREE
    if 'T' in letterCounts and letterCounts['T'] != 0:
        x = letterCounts['T']
        counts[3] = x
        letterCounts['T'] -= x
        letterCounts['H'] -= x
        letterCounts['R'] -= x
        letterCounts['E'] -= x
        letterCounts['E'] -= x
    #NINE
    if 'I' in letterCounts and letterCounts['I'] != 0:
        x = letterCounts['I']
        counts[9] = x
        letterCounts['N'] -= x
        letterCounts['I'] -= x
        letterCounts['N'] -= x
        letterCounts['E'] -= x
    #ONE
    if 'O' in letterCounts and letterCounts['O'] != 0:
        x = letterCounts['O']
        counts[1] = x
        letterCounts['O'] -= x
        letterCounts['N'] -= x
        letterCounts['E'] -= x
    #SEVEN
    if 'S' in letterCounts and letterCounts['S'] != 0:
        x = letterCounts['S']
        counts[7] = x
        letterCounts['S'] -= x
        letterCounts['E'] -= x
        letterCounts['V'] -= x
        letterCounts['E'] -= x
        letterCounts['N'] -= x

    for x in letterCounts:
        if letterCounts[x] != 0:
            print 'Somethings wrong with ' + x

    finalStr = ''
    for digit in counts:
        finalStr += str(digit) * counts[digit]
        
    return ''.join(sorted(finalStr))

numCases = int(inputF.readline())

for i in range(numCases):
    line = inputF.readline().strip()
    digits = removeLetters(line)

    output.write('Case #' + str(i+1) + ': ')
    output.write(digits + '\n')

inputF.close()
output.close()
