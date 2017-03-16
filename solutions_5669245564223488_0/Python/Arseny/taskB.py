import sys
from math import factorial
from string import ascii_lowercase as LETTERS
from collections import defaultdict


MAX_MODULO = 1000000007


def remove_adj_dup(s):
    if not s:
        return s
    result = s[:1]
    for x in s[1:]:
        if x != result[-1]:
            result+= x
    return result


def solve(words):
    one_char = defaultdict(int)
    is_middle = defaultdict(int)
    is_first = defaultdict(int)
    is_last = defaultdict(int)
    join_to = defaultdict(lambda: None)

    long_words = 0
    for word in words:
        word = remove_adj_dup(word)
        s = word[0]
        f = word[-1]
        if len(word) == 1:
            one_char[s]+= 1
        else:
            if s == f:
                return 0
            long_words+= 1
            join_to[s] = f
            is_first[s]+= 1
            is_last[f]+= 1
            for x in word[1:-1]:
                is_middle[x]+= 1

    result = 1
    if long_words == 0:
        result = factorial(len(one_char)) % MAX_MODULO
        for c in LETTERS:
            result = (result * factorial(one_char[c])) % MAX_MODULO
        return result

    start_candidate = []
    free_chars = []
    for c in LETTERS:
        if is_middle[c] > 1:
            return 0
        if is_middle[c] > 0 and (is_first[c] > 0 or is_last[c] > 0 or one_char[c] > 0):
            return 0
        if is_first[c] > 1:
            return 0
        if is_last[c] > 1:
            return 0
        if is_first[c] > 0 and is_last[c] == 0:
            start_candidate.append(c)
        if one_char[c] > 0 and is_first[c] == 0 and is_last[c] == 0:
            free_chars.append(c)

    result = 1
    num_of_components = 0

    num_of_components+= len(free_chars)
    for c in free_chars:
        result = (result * factorial(one_char[c])) % MAX_MODULO

    for c in start_candidate:
        while c is not None:
            result = (result * factorial(one_char[c])) % MAX_MODULO
            c = join_to[c]
        num_of_components+= 1

    result = (result * factorial(num_of_components)) % MAX_MODULO

    return result


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for t in range(T):
        sys.stdin.readline()
        words = sys.stdin.readline().split()
        answer = solve(words)
        print "Case #{0}: {1}".format(t + 1, answer)
