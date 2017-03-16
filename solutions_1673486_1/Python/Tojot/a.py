#!/usr/bin/env python3

import sys
def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return
ints = get_ints()

def get_floats():
	for line in sys.stdin:
		for word in line.split():
			yield float(word)
	return
floats = get_floats()

T = next(ints)
for t in range(T):
	A = next(ints)
	B = next(ints)
	opt = B+2
	base = A+B+1
	if base < opt : opt = base
	prob = 1.0
	for i in range(1,A+1):
		apro = next(floats)
		prob *= apro
		exp = (base - 2*i) + (B + 1) * (1-prob)
		if exp < opt: opt = exp
	print("Case #",t+1,": ",float(opt),sep='')
