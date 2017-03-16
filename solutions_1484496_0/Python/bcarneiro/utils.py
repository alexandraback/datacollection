class InputReader():
	def __init__(self, filename, input_lines=1):
		file = open(filename, 'r')
		self.lines = file.readlines()
		self.lines = map(lambda s: s.rstrip('\n'), self.lines) # remove lineend of the lines
		
		self.input = []
		for i in range(0, input_lines):
			self.input.append(self.lines[0])
			self.lines.pop(0)
		
		file.close()
			
class OutputWriter():
	def __init__(self, filename, output_lines):
		file = open(filename, 'w')
		
		for i, line in enumerate(output_lines):
			file.write("Case #%d:%s\n" % (i+1, line))
		
		file.close()
