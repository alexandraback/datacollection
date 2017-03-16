from collections import Counter

def findoffset(word):
    for i in range(1, len(word)+1):
        if word[i:] == word[:-i]:
            return i

def solve(textlen, abc, word):
    abclen = len(abc)
    abc = Counter(abc)
    wordprob = 1
    for c in word:
        wordprob *= abc[c] / abclen
        if wordprob == 0:
            return 0
    wordoffset = findoffset(word)
    maxbananas = (textlen - (len(word) - wordoffset)) // wordoffset
    return maxbananas - (wordprob * maxbananas)


tcnum = int(input())

for tc in range(1, tcnum+1):
    _, _, textlen = map(int, input().split())
    abc = input()
    word = input()
    print("Case #{}: {:.7f}".format(tc, solve(textlen, abc, word)))