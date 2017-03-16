#!/usr/bin/python3

from common import *

table = [0] * 126
table[125]  = "555"
table[100]  = "455"
table[75]   = "355"
table[50]   = "255"
table[80]   = "445"
table[60]   = "345"
table[40]   = "245"
table[45]   = "335"
table[30]   = "235"
table[20]   = "225" #145
table[64]   = "444"
table[48]   = "344"
table[32]   = "244"
table[36]   = "334"
table[24]   = "234"
table[16]   = "224" #144
table[27]   = "333"
table[18]   = "233"
table[12]   = "223" #134
table[8]    = "222" #124

# say '2' when missing a digit
table[25]   = "255"
table[15]   = "235"
table[10]   = "225"
table[9]    = "233"
table[6]    = "223"
table[4]    = "222" #114

# two missing digits
table[5]    = "235"
table[3]    = "233"
table[2]    = "232"
table[1]    = "235"

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b > 0:
        q = a // b
        r = (a - b * q)
        a, b = b, r
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcms(xs):
    l = 1
    for x in xs:
        l = lcm(l, x)
    return l

def testcase(x):
    r, n, m, k = readintegers()
    writeline("Case #%d:" % x)
    for i in range(r):
        xs = readintegers()
        x = lcms(xs)
        writeline(table[x])

run_tests(testcase)
