
"""Google Code Jam Template Code
by Tiago Togores"""

import sys, getopt, random, math, numpy, scipy, pdb

class Data(object):
	def __init__(self):
		super(Data, self).__init__()
	def algorithm(self):
		y = self.y
		x = self.x
		path = ''
		if y > 0:
			path += 'SN' * (y)
		else:
			path += 'NS' * (-y)
		if x > 0:
			path += 'WE' * (x)
		else:
			path += 'EW' * (-x)
		return str(path)

def get_data():
	data = Data()
	[data.x, data.y] = [int(w) for w in raw_input().split()]
	return data

if __name__ == "__main__":
	for i in xrange(int(raw_input())):
		print 'Case #{0}: {1}'.format(i + 1, get_data().algorithm())
