#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		scores = map(int, self.scores.split())
		self.num = scores[0]
		self.surprising = scores[1]
		self.p_score = scores[2]
		self.scores = scores[3:]
		
	def solve(self):
		# Solve case
		
		winners = 0
		
		for s in self.scores:
			# Check if it is surprising for the contestant
			# to have beaten the p_score
			base_score = s/3
			left_over = s%3

			if base_score >= self.p_score:
				winners += 1
				
			elif left_over >= 1 and base_score+1 >= self.p_score:
				winners += 1
			
			elif left_over == 0 and base_score+1 >= self.p_score and s > 0 and self.surprising > 0:
				winners += 1
				self.surprising -= 1
			
			elif left_over >= 2 and base_score+2 >= self.p_score and self.surprising > 0:
				winners += 1
				self.surprising -= 1
		
		self.answer = winners
	
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
	
	params = ["scores"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
