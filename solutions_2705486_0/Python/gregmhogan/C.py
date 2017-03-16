#!/usr/bin/env python

import math

memoize = {}

def run_one(S, words):
    if len(S) == 0:
        return 0

    if S in memoize:
        return memoize[S]

    # possibilities:
    #  S is in words
    #  S has prefix in words
    # for each, could be multiple words

    options = []

    # words are length 1 to 10
    for l in range(1, min(10, len(S)) + 1):
        if S[:l] in words:
            #print S[:l]
            options.append(run_one(S[l:], words))
        else:
            for i in range(l):
                one_wildcard = S[:i] + '?' + S[i+1:l]
                #print l, i, one_wildcard
                if one_wildcard in words:
                    options.append(1 + run_one(S[l:], words))
                else:
                    for j in range(i+5, l):
                        two_wildcards = one_wildcard[:j] + '?' + one_wildcard[j+1:]
                        #print l, i, j, two_wildcards
                        if two_wildcards in words:
                            options.append(2 + run_one(S[l:], words))

    changed = min(options)
    #print S, changed, options

    memoize[S] = changed
    return changed


def run(lines):
    output = []

    # Read dictionary, should be a set (values not needed)
    words = {}

    with open('garbled_email_dictionary.txt') as dictionary:
        for word in dictionary.readlines():
            word = word.rstrip('\r\n')

            words[word] = 0

            for i in range(len(word)):
                one_wildcard = word[:i] + '?' + word[i+1:]
                words[one_wildcard] = 1
                #print i, one_wildcard

                for j in range(i + 5, len(word)):
                    two_wildcards = one_wildcard[:j] + '?' + one_wildcard[j+1:]
                    words[two_wildcards] = 2
                    #print i, j, one_wildcard, two_wildcards

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        S = lines.popleft().rstrip('\r\n')

        result = run_one(S, words)

        output.append('Case #{0}: {1}'.format(t + 1, result))

    return output


# Google Code Jam submissions must run stand-alone.
# This code shall be copied into each solution.
if __name__ == '__main__':
    import os
    import sys
    from collections import deque

    infile = sys.argv[1]
    with open(infile) as file:
        lines = deque(file.readlines())
        output = run(lines)
        print os.linesep.join(output)
