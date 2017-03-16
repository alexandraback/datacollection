import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    r = params[0]
    c = params[1]
    w = params[2]
    divisions = c/w
    if c%w==0:
        wrong = 0
    else: wrong = 1
    guesses = divisions + wrong + w - 1
    if r > 1:
        ans = guesses + (r - 1)*divisions
    else:
        ans = guesses
    print "Case #"+str(i)+": "+str(ans)

for i in xrange(1, num_cases+1):
    do_calc(i)
