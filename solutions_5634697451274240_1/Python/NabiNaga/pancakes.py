
def min_flips(s):
	n = len(s)
	s = list(s)
	last_minus = -1
	for i in xrange(n):
		if s[i] == '-':
			last_minus = i
	if last_minus == -1:
		return 0
	flips = 1
	for i in xrange(last_minus-1,-1,-1):
		if s[i] != s[i+1]:
			flips += 1
	return flips

output = []
with open('pancake_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,str(min_flips(line.strip()))))

with open('pancake_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)




# Code to brute force for small values, checking the validity of my algorithm 
'''
import numpy as np

def brute(s):
	sss = set()
	n = len(s)
	s = np.array([1 if c=='+' else -1. for c in s])
	options = [s]
	sss.add(tuple(s))
	flips = 0
	while True:
		n_ops = []
		for op in options:
			if np.sum(op) == n:
				return flips
			for i in xrange(1,n+1):
				built = np.append((-op[:i])[::-1],op[i:])
				if tuple(built) not in sss:
					n_ops.append(built)
					sss.add(tuple(built))
		options = n_ops
		flips += 1

def compare(s):
	mf, b = min_flips(s), brute(s)
	#print s, mf, b
	assert mf == b

def gen(x):
	if x == 1:
		return ['+','-']
	ll = []
	for s in gen(x-1):
		ll.append(s+'+')
		ll.append(s+'-')
	return ll

for n in xrange(1,15):
	print "------------------------------- ", n, " --------------------"
	for s in gen(n):
		compare(s)

'''