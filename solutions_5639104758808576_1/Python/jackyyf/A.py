from fractions import Fraction as F
import math
import sys

fi = sys.stdin
fo = sys.stdout
fe = sys.stderr
exit = sys.exit

readline = raw_input

def readargs(tp=None):
	if tp is not None:
		return map(tp, readline().split())
	return readline().split()

def yesno(flag, yes='', no=''):
	if flag:
		print yes if yes else 'YES'
	else:
		print no if no else 'NO'

current_case = 0

def printcase():
    global current_case
    current_case += 1
    print 'Case #%d:' % current_case,

truefalse = lambda flag : yesno(flag, yes='TRUE', no='FALSE')

cases = int(readline())
for i in range(cases):
    s, bs = readargs()
    s = int(s)
    bs = map(int, bs)
    now = 0
    ans = 0
    for i in range(s + 1):
        if now < i:
            ans += 1
            now += 1
        now += bs[i]
    printcase()
    print ans
