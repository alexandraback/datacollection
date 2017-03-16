import sys
from collections import Counter

words = (["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"])
words = map(Counter, words)

def get_max_words(word, letters):
    ans = 1000000000
    for l in word:
        ans = min(ans, letters[l] / word[l])
    return ans

def sub_letters(word, letters, k):
    for l in word:
        letters[l] -= word[l] * k

def add_letters(word, letters, k):
    for l in word:
        letters[l] += word[l] * k

def bin_search(idx, letters):
    if idx == 10:
        for l in letters:
            if letters[l] != 0:
                return False
        return ""
    word = words[idx]
    max_words = get_max_words(word, letters)
    for i in range(max_words+1):
        sub_letters(word, letters, i)
        result = bin_search(idx+1, letters)
        if result != False:
            result = str(idx) * i + result
            return result
        add_letters(word, letters, i)
    return False



T = int(raw_input())
for case_idx in xrange(1, T+1):
    sys.stdout.write("Case #{}: ".format(case_idx))
    s = raw_input().strip()
    letters = Counter(s)
    result = bin_search(0, letters)
    if result == False:
        sys.stderr.write("OLOLOOOOOOOOOOOOOO!!!")
    print result


