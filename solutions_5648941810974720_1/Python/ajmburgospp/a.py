from fractions import Fraction as F
from collections import Counter
a = 'zero,one,two,three,four,five,six,seven,eight,nine'.upper().split(',')
ac = [Counter(x) for x in a]
# print(ac)
rev_map = sorted(set('zeroonetwothreefourfivesixseveneightnine'.upper()))
aletters = rev_map
rev_map = {x:seq for seq, x in enumerate(rev_map)}
# for seq, k in enumerate(ac):
# 	print seq, k
def create_mat(letters):
	c = Counter(letters)
	for l in rev_map.keys():
		if l not in c:
			c[l] = 0
	mat = [[0]*11 for x in xrange(len(rev_map))]

	for letter, count in c.iteritems():
		mat[rev_map[letter]][-1] = F(count)
		for digit in xrange(10):
			mat[rev_map[letter]][digit] = F(ac[digit][letter])
	return mat

def printsorted(mat):
	for m in sorted(mat, reverse=True):
		print [int(x) for x in m]

T = int(raw_input())
for kei in xrange(1,T+1):
	s = raw_input()
	numlets = len(rev_map)
	mat = create_mat(s)
	for j in xrange(10):
		# Get pivot row
		pidx = None
		for i in xrange(len(mat)):
			if mat[i][j] != 0:
				pidx = i
		if pidx is None: continue
		# Swap pivot row with jth row
		mat[j], mat[pidx] = mat[pidx], mat[j]
		# Normalize pivot row
		d = mat[j][j]
		for i in xrange(11):
			mat[j][i] /= d
		# Use pivot row to subtract, to make col j all 0s
		for m in xrange(len(mat)):
			# multiply row by this, so that m[j] - mul*pivot[j] = 0
			# don't cancel own pivot
			if m == j: continue
			# no need to cancel if col is already zero
			if mat[m][j] == 0: continue
			mul = mat[m][j]
			for k in xrange(11):
				mat[m][k] -= mat[j][k]*mul
		s = 0
		for i in xrange(len(mat)):
			for k in xrange(j+1):
				if mat[i][k] != 0:
					s += 1

	sold = Counter()
	for m in mat:
		idx = -1
		for i in xrange(len(m)-1):
			if m[i] == 1:
				if idx < 0:
					idx = i
				else:
					idx = -1
		if idx >= 0:
			sold[idx] = int(m[-1])
	arr = [str(i)*sold[i] for i in xrange(10)]
	print "Case #{}: {}".format(kei, ''.join(arr))