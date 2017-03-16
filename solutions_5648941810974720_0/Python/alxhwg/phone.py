import sys
import string

def main():
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        s = inF.readline()

        k = solve(s[:-1])

        ouF.write("Case #{0}: {1}\n".format(i+1, k))
    inF.close()
    ouF.close()

def getLetters(s):
    counts = {}
    for letter in ['E', 'G', 'F', 'I', 'H', 'O', 'N', 'S', 'R', 'U', 'T', 'W', 'V', 'X', 'Z']:
        counts[letter] = 0
    for letter in s:
        counts[letter] += 1
    return counts

def solve(s):
    counts = getLetters(s)
    nums = []
    while counts['Z'] > 0: #0
        nums.append(0)
        counts['Z'] -= 1
        counts['E'] -= 1
        counts['R'] -= 1
        counts['O'] -= 1
    while counts['W'] > 0: #2
        nums.append(2)
        counts['T'] -= 1
        counts['W'] -= 1
        counts['O'] -= 1
    while counts['U'] > 0: #4
        nums.append(4)
        counts['F'] -= 1
        counts['O'] -= 1
        counts['U'] -= 1
        counts['R'] -= 1
    while counts['X'] > 0: #6
        nums.append(6)
        counts['S'] -= 1
        counts['I'] -= 1
        counts['X'] -= 1
    while counts['G'] > 0: #8
        nums.append(8)
        for letter in 'EIGHT':
            counts[letter] -= 1
    while counts['T'] > 0: #3
        nums.append(3)
        for letter in 'THREE':
            counts[letter] -= 1
    while counts['F'] > 0: #5
        nums.append(5)
        for letter in 'FIVE':
            counts[letter] -= 1
    while counts['V'] > 0: #7
        nums.append(7)
        for letter in 'SEVEN':
            counts[letter] -= 1
    while counts['O'] > 0: #1
        nums.append(1)
        for letter in 'ONE':
            counts[letter] -= 1
    while counts['I'] > 0: #9
        nums.append(9)
        for letter in 'NINE':
            counts[letter] -= 1
    list.sort(nums)
    return ''.join(str(n) for n in nums)

main()
