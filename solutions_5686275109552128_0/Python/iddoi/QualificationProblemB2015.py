from abc import ABCMeta, abstractmethod
import math

class InputFileReader(object):
	def __init__(self, filename):
		self.input_file = open(filename + '.in', 'r')
	
	def read_int(self):
		return int(self.read_string())

	def read_int_list(self, separator):
		number_strings = self.read_string_list(separator)
		return [int(item) for item in number_strings]

	def read_float_list(self, separator):  
		number_strings = self.read_string_list(separator)
		return [float(item) for item in number_strings]  

	def read_string_list(self, separator):
		line = self.read_string()
		string_tuple = tuple((line.split(separator)))
		return string_tuple

	def read_string(self):
		line = self.input_file.readline()
		if ('\n' == line[-1]):
			line = line[:-1]
		return line
		
class OutputFileWriter(object):
	def __init__(self, filename):
		self.output_file = open(filename + '.out', 'w')
		self.case_num = 1
		
	def write(self, string_list):
		for out_string in string_list:
			self.output_file.write('Case #%d: %s\n' % (self.case_num, out_string))
			self.case_num += 1
			
	
class Problem(object):
	__metaclass__ = ABCMeta
	
	def __init__(self, filename):
		self.input_reader = InputFileReader(filename)
		self.output_writer = OutputFileWriter(filename)
		self.results = []
		self.initialize_from_input()
		
	@abstractmethod
	def initialize_from_input(self):
		pass
		
	@abstractmethod
	def solve_case(self):
		pass
		
	def solve(self):
		for i in xrange(self.number_of_cases):
			self.solve_case()
		self.output_writer.write(self.results)

		
class CommonProblem(Problem):
	__metaclass__ = ABCMeta
		
	def initialize_from_input(self):
		self.number_of_cases = self.input_reader.read_int()
		
def solve_problem(diner_list):
	diner_list.sort()
	diner_list.reverse()
	diner_list.append(0)
	split_minutes = 0
	while(True):
		max_diner = diner_list[0]
		split_num = 0
		should_split = False
		for i in xrange(0,len(diner_list)-1):
			reference_number = max(int(math.ceil(max_diner/2.0)), diner_list[i+1])
			split_num += 1
			if (max_diner - reference_number >= split_num):
				should_split = True
				break
		if should_split:
			for i in xrange(split_num):
				current_diner = diner_list[0]
				diner_list.append(current_diner/2)
				diner_list.append(current_diner - current_diner/2)
				diner_list.remove(current_diner)
			split_minutes += split_num
		else:
			break
		diner_list.sort()
		diner_list.reverse()
	return (split_minutes+max(diner_list))

class CurrentProblem(CommonProblem):
	def solve_case(self):
		number_of_initial_diners = self.input_reader.read_int()
		diner_list = self.input_reader.read_int_list(" ")
		result = solve_problem(diner_list)
		self.results.append(str(result))

		
		
if "__main__" == __name__:
	filename = "B-small-attempt0"
	current_problem = CurrentProblem(filename)
	current_problem.solve()