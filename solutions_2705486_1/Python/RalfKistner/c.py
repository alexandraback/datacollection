#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

words = set([w.strip() for w in open('garbled_email_dictionary.txt', 'r').readlines()])


alphabet = 'abcdefghijklmnopqrstuvwxyz'

def setletter(word, index, letter):
    return word[:index] + letter + word[index+1:]


import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    S = fin.readline().strip()

    dp = []
    dp.append([0]*5)

    for i in range(len(S)):
        dp.append([10**10]*5)

    for i, c in enumerate(S):
        # j = 0 means the letter at i-1 changed
        # j = 4 means the letter at i-5 changed
        # the letter at i-j-1 was the last letter that changed
        for j in range(5):
            for l in range(1, 11):
                if i + l > len(S):
                    break

                best = None
                word = S[i:i + l]
                if word in words:
                    newj = min(4, j + l)
                    best = 0
                    dp[i + l][newj] = min(dp[i + l][newj], dp[i][j])
                else:
                    # i + p1 - 5 must be >= i-j-1
                    # =>  p1 >= 4 - j
                    for p1 in range(4 - j, l):
                        if best is not None:
                            break
                        for letter in alphabet:
                            word1 = setletter(word, p1, letter)

                            if word1 in words:
                                # last letter => j=0
                                newj = min(4, l - (p1 + 1))
                                best = 1
                                dp[i + l][newj] = min(dp[i + l][newj], dp[i][j] + 1)
                                break
                            else:
                                for p2 in range(p1 + 5, l):
                                    if best is not None:
                                        break
                                    newj = min(4, l - (p2 + 1))

                                    for letter in alphabet:
                                        word2 = setletter(word1, p2, letter)

                                        if word2 in words:
                                            best = 2
                                            dp[i + l][newj] = min(dp[i + l][newj], dp[i][j] + 2)
                                            break





    #print(dp, file=sys.stderr)
    result = min(dp[-1])
    print("Case #%d: %s" % (case, result))

