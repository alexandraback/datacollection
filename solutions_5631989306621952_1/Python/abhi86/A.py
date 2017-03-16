#!/usr/bin/env python

def get_min_last_word(s):
    last_word = ''
    for si in s:
        if len(last_word) >0 and si < last_word[0]:
            last_word += si
        else:
            last_word = si + last_word
    return last_word

if __name__ == '__main__':
    T = int(raw_input())
    for tc in range(1, T + 1):
        s = raw_input()
        print 'Case #%d: %s' % (tc, get_min_last_word(s))
