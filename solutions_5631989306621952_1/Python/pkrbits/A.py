#! /usr/bin/env python


def last_word(str):
    if not str:
        return ""

    word_char_list = [str[0]]
    for i in range(1, len(str)):
        if str[i] >= word_char_list[0]:
            word_char_list.insert(0, str[i])
        else:
            word_char_list.append(str[i])
    return ''.join(word_char_list)

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    S = str(raw_input())
    print("Case #{}: {}".format(i, last_word(S)))
