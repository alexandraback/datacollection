#!/usr/bin/python2.7

import sys

CHAR_MAP = {
    'y' : 'a',
    'e' : 'o',
    'q' : 'z'
}

CHAR_MAP =  {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def nsum(n):
    i = 0
    for j in range(1, n+1):
        i += j
    return i

def train(in_file, out_file):
    in_text  = " ".join([l.strip() for l in in_file.readlines()[1:]])
    out_text = " ".join([l.split(":")[1].strip() for l in out_file.readlines()])

    for i_char, o_char in zip(in_text, out_text):
        if i_char != ' ':
            CHAR_MAP[i_char] = o_char

    i_tot = 0
    o_tot = 0
    for i, o in CHAR_MAP.items():
        i_tot += ord(i) - 96
        o_tot += ord(o) - 96

    sum26 = nsum(26)

    CHAR_MAP[chr(sum26 - i_tot + 96)] = chr(sum26 - o_tot + 96)

    print CHAR_MAP

def translate(in_file):
    return ["".join([CHAR_MAP[c] if c != ' ' else c
                     for c in l.strip()])
            for l in in_file.readlines()[1:]]

if len(sys.argv) == 3:
    train(open(sys.argv[1]), open(sys.argv[2]))
elif len(sys.argv) == 2:
    i = 1
    for case in translate(open(sys.argv[1])):
        print "Case #%d: %s" % (i, case)
        i += 1
