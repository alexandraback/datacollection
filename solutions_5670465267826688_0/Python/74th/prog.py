#!/usr/bin/env python3
# coding: UTF-8

import sys,math

DEBUG = True
DEBUG = False

qNum = int(sys.stdin.readline())
def debug(s1,s2):
    if DEBUG :
        print(str(s1) + ":" + str(s2))

table = {
        ("1","i"):("+","i"),
        ("1","j"):("+","j"),
        ("1","k"):("+","k"),
        ("i","i"):("-","1"),
        ("i","j"):("+","k"),
        ("i","k"):("-","j"),
        ("j","i"):("-","k"),
        ("j","j"):("-","1"),
        ("j","k"):("+","i"),
        ("k","i"):("+","j"),
        ("k","j"):("-","i"),
        ("k","k"):("-","1"),
        }

def calc(f,c1,c2):
    s = table[(c1,c2)]
    if s[0] == f :
        return ("+",s[1])
    else:
        return ("-",s[1])

def ans(q):
    a = 0

    l = sys.stdin.readline().strip().split(" ")
    L = int(l[0])
    X = int(l[1])
    l = sys.stdin.readline().strip()
    letter = l * X
    debug("letter",letter)

    # i を探す
    p = "+"
    c = "1"
    find = False
    while len(letter) > 0 :
        debug("letter",letter)
        (p,c) = calc(p,c,letter[0])
        letter = letter[1:]
        debug("(c,p)",(c,p))
        if c == "i" and p == "+" :
            find = True
            break
    if not find :
        print("Case #" + str(q) + ": NO")
        return

    # j を探す
    p = "+"
    c = "1"
    while len(letter) > 0 :
        debug("letter",letter)
        (p,c) = calc(p,c,letter[0])
        letter = letter[1:]
        debug("(c,p)",(c,p))
        if c == "j" and p == "+" :
            break
    if not find :
        print("Case #" + str(q) + ": NO")
        return

    # k まで集約する
    p = "+"
    c = "1"
    while len(letter) > 0 :
        debug("letter",letter)
        (p,c) = calc(p,c,letter[0])
        letter = letter[1:]
        debug("(c,p)",(c,p))
    if c == "k" and p == "+" :
        print("Case #" + str(q) + ": YES")
    else:
        print("Case #" + str(q) + ": NO")

    #sys.stderr.write("Case #" + str(q) + ": " + str(a))
    pass

for q in range(qNum):
    ans(q+1)
