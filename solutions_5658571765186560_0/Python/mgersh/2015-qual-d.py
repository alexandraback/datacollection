import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    x = params[0]
    r = params[1]
    c = params[2]
    if r < c:
        temp = c
        c = r
        r = temp
    if x == 1:
        winner = "GABRIEL"
    if x == 2:
        if (r*c)%2 == 0:
            winner = "GABRIEL"
        else:
            winner = "RICHARD"
    if x == 3:
        if (r*c)%3 == 0 and r > 1 and c > 1:
            winner = "GABRIEL"
        else:
            winner = "RICHARD"
    if x == 4:
        if (r*c)%4 != 0:
            winner = "RICHARD"
        else:
            if r == 2 and c == 2:
                winner = "RICHARD"
            elif r == 4:
                if c == 1:
                    winner = "RICHARD"
                elif c == 2:
                    winner = "RICHARD"
                elif c == 3:
                    winner = "GABRIEL"
                elif c == 4:
                    winner = "GABRIEL"
    print "Case #"+str(i)+": "+winner

for i in xrange(1, num_cases+1):
    do_calc(i)
