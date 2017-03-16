#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		self.contestants = map(int, self.contestants.split(' ')[1:])
			
	def solve(self):
		# Solve case
		tally = sum(self.contestants)
		audience = tally
		cs = len(self.contestants)
		self.answer = [0]*cs
		
		for (c, contestant) in enumerate(self.contestants):
			votes = (2.0*audience)/cs - contestant
			pc = votes/float(audience) * 100
			self.answer[c] = pc
		
		
		not_in = sum([x>=0 for x in self.answer])

		for (s, score) in enumerate(self.answer):
			if score < 0:

				for (a, answer) in enumerate(self.answer):
					if answer >= 0:
						self.answer[a] += score/float(not_in)

		for (s, score) in enumerate(self.answer):
			if score < 0:
				self.answer[s] = 0
			
		self.answer = ' '.join(map(str, self.answer))
	
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
	
	params = ["contestants"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
