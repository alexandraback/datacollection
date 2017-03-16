#!/usr/bin/env python

from __future__ import print_function
import sys

letters = "abcdefghijklmnopqrstuvwxyz"

googlerese = ["ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv"]

english = ["our language is impossible to understand",
        "there are twenty six factorial possibilities",
        "so it is okay if you want to just give up"]

translation = {}

def find_mapping():
    global googlerese
    global english
    global translation

    num_examples = len(googlerese)
    for i in range(num_examples):
        str_len = len(googlerese[i])
        for j in range(str_len):
            if not(googlerese[i][j] in translation):
                translation[googlerese[i][j]] = english[i][j]
            elif(translation[googlerese[i][j]] != english[i][j]):
                print("mismatch!")

def deduce_missing():
    global translation
    global letters

    keys = translation.keys()
    values = translation.values()
    missing_key = ''
    missing_value = ''
    for character in letters:
        if not(character in keys):
            missing_key = character
        if not(character in values):
            missing_value = character
    translation[missing_key] = missing_value

def main(*args):
    global translation

    if(len(args) < 2):
        print("Usage: %s <input file>" % args[0])

    filename = args[1]
    input_file = open(filename, "rb")
    output_file = open(filename+".out", "wb")

    find_mapping()
    translation['y'] = 'a';
    translation['e'] = 'o';
    translation['q'] = 'z';
    deduce_missing()

    try:
        in_str = input_file.readline().strip()
    except:
        print("Premature end of input")

    T = int(in_str)
    for k in range(T):
        in_str = input_file.readline().strip()
        out_str = ''
        for character in in_str:
            out_str += translation[character]
        print("Case #%d: %s" % (k+1, out_str), file=output_file)

    print(translation)
    print(len(translation))

    input_file.close()
    output_file.close()


if(__name__ == "__main__"):
    sys.exit(main(*sys.argv))
