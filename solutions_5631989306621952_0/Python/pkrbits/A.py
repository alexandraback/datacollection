#! /usr/bin/env python

def last_word(str):
    if not str:
        return ""

    word = str[0]
    for i in range(1, len(str)):
        if str[i] >= word[0]:
            word = str[i] + word
        else:
            word += str[i]
    return word

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    S = str(raw_input())
    print("Case #{}: {}".format(i, last_word(S)))
