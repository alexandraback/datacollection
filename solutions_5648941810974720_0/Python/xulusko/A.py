from sys import stdin

spelled = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
letters = {}
for word in spelled:
    for letter in word: letters[letter] = 0

def subtract(no, ch):
    cnt = letters[ch]
    for letter in spelled[no]:
        letters[letter] -= cnt
    return cnt*str(no)

data = stdin.readlines()

for no, case in enumerate(data[1:], 1):
    for letter in case[:-1]: letters[letter] += 1

    ans = ''
    ans += subtract(0, 'Z')
    ans += subtract(2, 'W')
    ans += subtract(6, 'X')
    ans += subtract(8, 'G')
    ans += subtract(3, 'H')
    ans += subtract(4, 'R')
    ans += subtract(5, 'F')
    ans += subtract(1, 'O')
    ans += subtract(7, 'V')
    ans += subtract(9, 'I')

    ans = ''.join(sorted(ans))
    print('Case #{}: {}'.format(no, ans))
