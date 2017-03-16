
import jammly
import math


RANGES = [
	(1,9),(10,99),(100,999),(1000,9999),(10000,99999)
	,(100000,999999), (1000000,2000000)
]

def calcData():
	data = {}
	for a,b in RANGES:
		print "calc", a, b

		digits = len(str(a))
		ps = data[digits] = []

		for i in range(a,b):
			gen = {}
			for r in range(1,digits):
				j = str(i)
				j = int(j[digits-r:] + j[:digits-r])
				
				if len(str(j)) != digits:
					continue
				
				if j <= i:
					continue
				
				if not j in gen:
					ps.append((i,j))
					gen[j] = True
	print "got data"
	return data

PAIRS = calcData()


#print PAIRS

TEST = \
"""4
1 9
10 40
100 500
1111 2222
1000000 2000000"""

class Jam(jammly.Jam):
	r"""
	>>> Jam().runTest(TEST)
	Case #1: 0
	Case #2: 3
	Case #3: 156
	Case #4: 287
	"""
	

	def jam(self, line):
		a, b = map(int,line.split(" "))
		
		d = len(str(a))
		ps = PAIRS[d]
		
		c = 0
		for i,j in ps:
			if a <= i and j <= b:
				c += 1
		
		return c


if __name__ == "__main__":
	Jam.start()
