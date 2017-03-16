# -*- coding: utf-8 -*-

def cleanstr(s, w, n):
    r = s[:]
    t = []
    for c in w:
        if c in t:
            continue
        else:
            t.append(c)
        i = r.count(c)
        r = r.replace(c, "")
        r += c * (i-n)
    return r


def solve(num):
    r = num[:]

    n0 = r.count("Z")
    r = cleanstr(r, "ZERO", n0)

    n2 = r.count("W")
    r = cleanstr(r, "TWO", n2)

    n6 = r.count("X")
    r = cleanstr(r, "SIX", n6)

    n7 = r.count("S")
    r = cleanstr(r, "SEVEN", n7)

    n8 = r.count("G")
    r = cleanstr(r, "EIGHT", n8)

    n3 = r.count("H")
    r = cleanstr(r, "THREE", n3)

    n4 = r.count("U")
    r = cleanstr(r, "FOUR", n4)

    n5 = r.count("F")
    r = cleanstr(r, "FIVE", n5)

    n9 = r.count("I")
    r = cleanstr(r, "NINE", n9)

    n1 = r.count("O")
    r = cleanstr(r, "ONE", n1)

    return "0"*n0 + "1"*n1 + "2"*n2 + "3"*n3 + "4"*n4 + "5"*n5 + "6"*n6 + "7"*n7 + "8"*n8 + "9"*n9


t = int(input())
for i in range(1,t+1):
    num = input()
    print("Case #" + str(i) + ": " + solve(num))
