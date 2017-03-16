#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		self.A, self.B = map(int, self.range.split())
			
	def solve(self):
		# Solve case
		recycles = {}
		r = 0
		for n in xrange(self.A, self.B+1):
			num = str(n)
			recycled = False
			
			for x in xrange(len(num)):
				num = num[-1] + num[:-1]
				
				if num in recycles:
					r += recycles[num]
					recycles[num] += 1
					recycled = True
					break
			
			if not recycled:
				recycles[num] = 1
		
		self.answer = r
	
	def __str__(self):
		return "Case #%d: %s" % (self.number, self.answer)

class CaseParser():
	def __init__(self, infile, parameters):
		self.parameters = parameters

		self.infile = infile
		self.num_cases = None
	
	def cases(self):
		# Get the number of cases
		self.num_cases = int(self.infile.readline())

		for c in xrange(self.num_cases):
			# The properties for this case...
			props = {}
			for p in self.parameters:
				props[p] = self.infile.readline()
		
			yield Case(c+1, props)


if __name__ == "__main__":
	try:
		import sys
		infile_path = sys.argv[1]
	except IndexError:
		infile_path = "infile_path"
	infile = open(infile_path)
	
	params = ["range"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
