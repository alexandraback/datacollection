from collections import Counter

t = int(input())
for testCase in range(1, t + 1):
    s = input()
    cnt = Counter()
    for c in s:
        cnt[c] += 1
    digits = [0 for digit in range(10)]
    digits[0] = cnt['Z']
    for c in 'ZERO':
        cnt[c] -= digits[0]

    digits[2] = cnt['W']
    for c in 'TWO':
        cnt[c] -= digits[2]

    digits[4] = cnt['U']
    for c in 'FOUR':
        cnt[c] -= digits[4]

    digits[6] = cnt['X']
    for c in 'SIX':
        cnt[c] -= digits[6]

    digits[8] = cnt['G']
    for c in 'EIGHT':
        cnt[c] -= digits[8]

    ##########################

    digits[1] = cnt['O']
    for c in 'ONE':
        cnt[c] -= digits[1]

    digits[3] = cnt['R']
    for c in 'THREE':
        cnt[c] -= digits[3]

    digits[5] = cnt['F']
    for c in 'FIVE':
        cnt[c] -= digits[5]

    #########################

    digits[7] = cnt['V']
    digits[9] = cnt['I']

    print("Case #{}: {}".format(testCase, ''.join(digits[i] * str(i) for i in range(10))))
