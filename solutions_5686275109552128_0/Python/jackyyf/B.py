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

############### MAIN ###############

calc = lambda P, d : sum(map(lambda x : int(math.ceil(x * 1. / d)), P)) - len(P) + d


cases = int(readline())
for i in range(cases):
    Ans = 0x12345678
    D = int(readline())
    P = readargs(int)
    Pmax = max(P)
    for d in range(1, Pmax + 1):
        Ans = min(Ans, calc(P, d))
    printcase()
    print Ans
