
"""Google Code Jam Template Code
by Tiago Togores"""

import sys, getopt, random, math, numpy, scipy, pdb

class Data(object):
	def __init__(self):
		super(Data, self).__init__()
	def algorithm(self):
		l = len(self.name)
		# lc = [0] * l
		# c = 0
		# mc = 0
		# for i in xrange(l):
		# 	if lc[i] in ('a', 'e', 'i', 'o', 'u'):
		# 		c = 0
		# 	else:
		# 		c += 1
		# 	mc = max(mc, c)
		# 	lc[i] = mc
		# return str(max(lc))
		m = 0
		for i, c1 in enumerate(self.name):
			for j, c2 in enumerate(self.name):
				if i <= j:
					cc = 0
					mcc = 0
					for c in self.name[i:j+1:]:
						if c in ('a', 'e', 'i', 'o', 'u'):
							cc = 0
						else:
							cc += 1
						if cc == self.n:
							mcc += 1
							break
							# print self.name[i:j+1:], cc
					m += mcc
		return str(m)



def get_data():
	data = Data()
	[data.name, data.n] = [w for w in raw_input().split()]
	data.n = int(data.n)
	return data

if __name__ == "__main__":
	for i in xrange(int(raw_input())):
		print 'Case #{0}: {1}'.format(i + 1, get_data().algorithm())
