#!/usr/bin/env python

# Find the mapping from the sample input and output:
#
#known_words = [('a zoo', 'y qee'),
#               ('ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand'),
#               ('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities'),
#               ('de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up'),
#               ('q', 'z')]  # the previous words have the other 25 letters
#
#mapping = {}
#for googlerese, english in known_words:
#    for i in range(len(googlerese)):
#        mapping[googlerese[i]] = english[i]
#
#print mapping


mapping = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def run_one(googlerese):
    english = ""

    for letter in googlerese:
        english += mapping[letter]

    return english


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        googlerese = lines.popleft().rstrip('\r\n')

        english = run_one(googlerese)

        output.append('Case #{0}: {1}'.format(t + 1, english))

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
