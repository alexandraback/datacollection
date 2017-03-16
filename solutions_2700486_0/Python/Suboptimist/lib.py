import sys

class InputFile(object):
	
	def __init__(self, file):
		self.file = file
		self.lines = self.file.readlines()

	def int(self):
		return int(self.lines.pop(0))

	def int_list(self):
		return [int(s) for s in self.lines.pop(0).split()]
	
	def int_tuple(self):
		return tuple(int(s) for s in self.lines.pop(0).split()) 

	def str(self):
		return self.lines.pop(0)

class OutputFile(object):
	
	def __init__(self, file):
		self.file = file
		
	def result(self, *args):
		if len(args)==1:
			self.file.write(args[0] + '\n')
		elif len(args)==2:
			self.file.write('Case #%d: %s\n' % (args[0], args[1]))
		else:
			raise NotImplementedError
	
def wrapper(solution):
	def wrapped(input_name=None, output_name=None):
		
		if input_name:
			input_file = open(input_name, 'r')
		elif len(sys.argv) > 1:
			input_file = open(sys.argv[1], 'r')
		else: 
			input_file = open("example.in")

		if output_name:
			output_file = open(output_name, 'w')
		elif len(sys.argv) > 2:
			output_file = open(sys.argv[2], 'w')
		else:
			output_file = sys.stdout

		solution(InputFile(input_file), OutputFile(output_file))
	return wrapped
