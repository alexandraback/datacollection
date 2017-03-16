from __future__ import print_function
import fileinput
from collections import Counter
from operator import mul


def matchprefix(word):
    for i in reversed(range(1, len(word))):
        if(word[:i] == word[len(word) - i:]):
            return i
    return 0


def wpcnt(sent_len, word_len, prefix_size, word_prob):
    print(word_prob)
    if(sent_len < word_len):
        return (
                (word_prob *
                    (1 +
                        wpcnt(sent_len - (word_len - prefix_size)) +
                        wpcnt(sent_len - word_len)) +
                (1 - word_prob) *
                    wpcnt(sent_len - 1, word_len, prefix_size, word_prob)))
    else:
        return 0


def stupid_mnk(keyboard, word, each_prob, sent_len):
    res = 0
    cur = []
    for i in range(sent_len):
        # print("char", i)
        cur.append([0, 1])
        new_cur = []
        for elem in cur:
            needed = elem[0]
            prob = elem[1]
            new_prob = each_prob[word[needed]] * prob
            # print(new_prob)
            if(needed + 1) == len(word):
                # print("adding a word with probability", new_prob)
                res += new_prob
            else:
                new_cur.append([needed + 1, new_prob])
        cur = new_cur
    return res


def monkeys(keyb_len, word_len, sent_len, keyboard, word):
    if(word_len > sent_len):
        return 0
    for c in word:
        if c not in keyboard:
            return 0
    # prefix_size = matchprefix(word)
    banana_count = (sent_len - word_len) / (word_len - matchprefix(word)) + 1
    cntr = Counter(keyboard)
    each_prob = {
        letter: float(cntr[letter]) / keyb_len for letter in set(word)}
    # word_prob = reduce(mul, [each_prob[letter] for letter in word])
    # print( * word_prob))
    return banana_count - stupid_mnk(keyboard, word, each_prob, sent_len)
    # ((sent_len / word_len) * word_prob)
    # return banana_count - wpcnt(sent_len, word_len, prefix_size, word_prob)


def solve(lines):
    k, l, s = map(int, lines[0].split())
    keyboard = lines[1][:-1]
    word = lines[2][:-1]
    return round(float(monkeys(k, l, s, keyboard, word)), 7)


def main():
    lines = ["", "", ""]
    for idx, line in enumerate(fileinput.input()):
        if idx > 0:
            lines[(idx - 1) % 3] = line
            if idx % 3 == 0:
                print("Case #{}: {}".format(idx / 3, solve(lines)))

if __name__ == '__main__':
    main()
