
from collections import defaultdict


def initial_bananas(S, L, keyboard, word):
    if set(word)-set(keyboard):
        return 0

    overlap = 0
    for i in xrange(L-1):
        if word[0:i+1] == word[L-i-1:L]:
            overlap = i+1
    start = 0
    bananas = 0
    while start+L <= S:
        start += L-overlap
        bananas += 1
    return bananas


def count_occurences(s, sub):
    cnt = 0
    idx = 0
    while idx < len(s):
        nextidx = s.find(sub, idx)
        if nextidx < 0:
            break
        idx = nextidx + 1
        cnt += 1
    return cnt


def solve(K, L, S, keyboard, word):
    wordcount = [0]
    words = defaultdict(float)
    def populate_words(candidate):
        if len(candidate) == S:
            words[candidate] += 1
            wordcount[0] += 1
        else:
            for l in keyboard:
                populate_words(candidate+l)

    populate_words("")
    wordcount = wordcount[0]
    bananas = initial_bananas(S, L, keyboard, word)
    pays = 0.0
    for written_word in words:
        pays += count_occurences(written_word, word)*words[written_word]/wordcount
    return bananas-pays

T = int(raw_input())
for t in xrange(1, T+1):
    K,L,S = map(int, raw_input().split())
    keyboard = raw_input().strip()
    word = raw_input().strip()
    print "Case #%d: %.7f" % (t, solve(K, L, S, keyboard, word))
