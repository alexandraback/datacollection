import sys
from collections import Counter

words = (["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"])
words = map(Counter, words)

def sub_letters(word, letters, k):
    for l in word:
        letters[l] -= word[l] * k

T = int(raw_input())
for case_idx in xrange(1, T+1):
    sys.stdout.write("Case #{}: ".format(case_idx))
    s = raw_input().strip()
    letters = Counter(s)
    ans = [0] * 10
    
    ans[0] = letters['Z']
    sub_letters(words[0], letters, ans[0])
    ans[2] = letters['W']
    sub_letters(words[2], letters, ans[2])
    ans[6] = letters['X']
    sub_letters(words[6], letters, ans[6])
    ans[8] = letters['G']
    sub_letters(words[8], letters, ans[8])
    ans[3] = letters['H']
    sub_letters(words[3], letters, ans[3])
    ans[4] = letters['R']
    sub_letters(words[4], letters, ans[4])
    ans[5] = letters['F']
    sub_letters(words[5], letters, ans[5])
    ans[7] = letters['S']
    sub_letters(words[7], letters, ans[7])
    ans[1] = letters['O']
    sub_letters(words[1], letters, ans[1])
    ans[9] = letters['I']
    sub_letters(words[9], letters, ans[9])

    for i in letters:
        assert letters[i] == 0

    for i in range(10):
        sys.stdout.write(str(i)*ans[i])

    print ""
