#!/usr/bin/env python

f = file('A.input', 'r')
inp = [ x for x in f.read().split('\n') ][:-1]
cases = int(inp.pop(0))

def add_wrong(B):
	return B + 1

def product(l):
	prod = 1
	for i in l:
		prod = prod * i
	return prod

def product_inverse(l):
	prod = 1
	for i in l:
		prod = prod * (1 - i)
	return prod

def perfect_bk_gain(x, remaining):
	return 2*x + remaining + 1

for i_case in range(1, cases+1):
	AB_inp = map(int, inp.pop(0).split(' '))
	A = AB_inp[0] # INT
	B = AB_inp[1] # INT
	remaining_chars = B - A
	probs = map(float, inp.pop(0).split(' ')) # LIST OF FLOAT, INDEXED AS A
	
	# K(give_up)
	lowest_exp = B + 2
	
	# K(keep typing)
	prob_correct = product(probs)
	keep_exp = prob_correct * (remaining_chars + 1) + (1 - prob_correct) * (remaining_chars + 1 + add_wrong(B))
	if keep_exp < lowest_exp:
		lowest_exp = keep_exp
	
	x = 1
	while True:
		if perfect_bk_gain(x, remaining_chars) < lowest_exp and x <= A:
			probs[A-x] = 1.0
			prob_correct = product(probs)
			bk_exp = prob_correct * (2*x + remaining_chars + 1) + (1 - prob_correct) * (2*x + remaining_chars + 1 + add_wrong(B))
			if bk_exp < lowest_exp:
				lowest_exp = bk_exp
		else:
			break
		x = x + 1
	
	result = lowest_exp
	print "Case #%d: %.6f" % (i_case, result)
