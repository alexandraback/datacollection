from abc import ABCMeta, abstractmethod

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
	
class SingleQuaternion(object):
	def __init__(self, character, sign):
		self.character = character
		self.sign = sign
		
def quaternion_mult(n1, n2):
	result = SingleQuaternion("1", n1.sign*n2.sign)
	if "1" == n1.character:
		result.character = n2.character
		return result
	if "1" == n2.character:
		result.character = n1.character
		return result
	if "i" == n1.character:
		if "i" == n2.character:
			result.character = "1"
			result.sign *= -1
		if "j" == n2.character:
			result.character = "k"
		if "k" == n2.character:
			result.character = "j"
			result.sign *= -1
	if "j" == n1.character:
		if "i" == n2.character:
			result.character = "k"
			result.sign *= -1
		if "j" == n2.character:
			result.character = "1"
			result.sign *= -1
		if "k" == n2.character:
			result.character = "i"
	if "k" == n1.character:
		if "i" == n2.character:
			result.character = "j"
		if "j" == n2.character:
			result.character = "i"
			result.sign *= -1
		if "k" == n2.character:
			result.character = "1"
			result.sign *= -1
	return result
	
def quaternion_digest(quaternion_string):
	quaternion = SingleQuaternion("1", 1)
	for i in xrange(len(quaternion_string)):
		current_quaternion = SingleQuaternion(quaternion_string[i], 1)
		quaternion = quaternion_mult(quaternion, current_quaternion)
	return quaternion
	
def find_char(input_string, char_to_find):
	quaternion = SingleQuaternion("1", 1)
	for i in xrange(len(input_string)):
		current_quaternion = SingleQuaternion(input_string[i], 1)
		quaternion = quaternion_mult(quaternion, current_quaternion)
		if ((quaternion.character == char_to_find) and (1 == quaternion.sign)):
			return i
	return -1
	
def is_legal(base_string, base_repetition):
	base_digest = quaternion_digest(base_string)
	
	if 0 == base_repetition%2:
		sign_multiplied = 1
	else:
		sign_multiplied = base_digest.sign
	
	total_quaternion = quaternion_digest(base_digest.character*(base_repetition%4))
	total_quaternion.sign *= sign_multiplied
	
	if (-1 != total_quaternion.sign):
		return False
	if ("1" != total_quaternion.character):
		return False
		
	i_index = find_char(base_string*min(4, base_repetition), "i")
	if (-1 == i_index):
		return False
	if i_index >= len(base_string)*base_repetition:
		return False		
	
	long_string = base_string*5
	j_index = find_char(long_string[i_index+1:i_index+1+4*len(base_string)], "j")
	if (-1 == j_index):
		return False
	if (i_index + j_index >= len(base_string)*base_repetition):
		return False
		
	return True
	
def simple_is_legal(base_string, base_repetition):
	full_string = base_string*base_repetition
	quaternion = SingleQuaternion("1", 1)
	found_i = False
	for i in xrange(len(full_string)):
		quaternion = quaternion_mult(quaternion, SingleQuaternion(full_string[i], 1))
		if (("i" == quaternion.character) and (1 == quaternion.sign)):
			found_i = True
			break
	if not found_i:
		return False
	if (i+1 >= len(full_string)):
		return False

	found_j = False
	quaternion = SingleQuaternion("1", 1)
	for j in xrange(i+1,len(full_string)):
		quaternion = quaternion_mult(quaternion, SingleQuaternion(full_string[j], 1))
		if (("j" == quaternion.character) and (1 == quaternion.sign)):
			found_j = True
			break
	if not found_j:
		return False
	if (j+1 >= len(full_string)):
		return False
	
	quaternion = SingleQuaternion("1", 1)
	for k in xrange(j+1,len(full_string)):
		quaternion = quaternion_mult(quaternion, SingleQuaternion(full_string[k], 1))
	
	return ((quaternion.character == "k") and (quaternion.sign == 1))

	
class CurrentProblem(CommonProblem):
	def solve_case(self):
		l = self.input_reader.read_int_list(" ")
		base_length = l[0]
		base_repetition = l[1]
		base_string = self.input_reader.read_string()
		if simple_is_legal(base_string, base_repetition):
			self.results.append("YES")
		else:
			self.results.append("NO")
		
if "__main__" == __name__:
	filename = "C-small-attempt3"
	current_problem = CurrentProblem(filename)
	current_problem.solve()