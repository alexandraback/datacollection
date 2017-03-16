#!/usr/bin/python3

import sys

a = "y qee" "ejp mysljylc kd kxveddknmc re jsicpdrysi" "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" "de kr kd eoya kw aej tysr re ujdr lkgc jvz"
b = "a zoo" "our language is impossible to understand" "there are twenty six factorial possibilities" "so it is okay if you want to just give upq"

tr = dict()
for j in range(0,len(a)):
    tr[a[j]] = b[j]


def tran(w):
    r = ""
    for i in w:
        r += tr[i]
    return r

G = int(sys.stdin.readline())
for i in range(1,G+1):
    print("Case #%s: %s" % (i, tran(sys.stdin.readline().strip())))
    

