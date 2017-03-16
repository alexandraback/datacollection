#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    S = list(raw_input().strip())
    done = False
    answer = 0
    while not done:
        i = 0
        if S[0] == "+":
            while i+1<len(S) and S[i+1] == "+":
                i += 1
            if i == len(S)-1: # last
                done = True
            else:
                S = list("-"*(i+1)) + S[i+1:]
                answer += 1
        else:
            while i+1<len(S) and S[i+1] == "-":
                i += 1
            if i == len(S)-1: # last
                done = True
            else:
                S = list("+"*(i+1)) + S[i+1:]
            answer += 1

    print "Case #%i: %s\n" % (t+1, answer)


