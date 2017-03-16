#!/usr/bin/python

class Osmos:

	def __init__(self,input_lines):
		#print input_lines
		self.osmos = [ int(i) for i in input_lines[1].split() ]
		self.osmos.sort()
		self.items_to_go = len(self.osmos)
		self.best_ans = self.items_to_go
		self.curr_size = int(input_lines[0].split()[0])
		self.added_so_far = 0
		#print self.osmos
		#print self.best_ans
		#print self.curr_size
	
	def solve(self):
		
		if self.curr_size == 1:
			return self.best_ans

		for i in xrange(len(self.osmos)):
			if self.curr_size <= self.osmos[i]:
				#print "next item to get to:" + str(self.osmos[i])
				while self.curr_size <= self.osmos[i]:
					#print "started adding"
					#print self.added_so_far
					#print self.curr_size
					self.curr_size += (self.curr_size - 1)
					self.added_so_far += 1
					#print self.added_so_far
					#print self.curr_size

			self.curr_size += self.osmos[i]
			self.items_to_go -= 1
			
			if (self.added_so_far + self.items_to_go) < self.best_ans:
				self.best_ans = self.added_so_far + self.items_to_go

			if (self.added_so_far > self.best_ans):
				return self.best_ans


		return self.best_ans



import sys
input_lines = open(sys.argv[1], "rt").readlines()
stripped_input_lines = [line.strip() for line in input_lines]
num_tests = int(input_lines[0])
#print num_tests
#print stripped_input_lines
for i in xrange(num_tests):

	osmos = Osmos(stripped_input_lines[i*2+1:i*2+3])
	result =  osmos.solve()
	print "Case #"+str(i+1)+": "+str(result)
