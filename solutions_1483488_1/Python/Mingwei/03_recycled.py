class Recycler(object):

	def __init__(self, lower_bound, upper_bound):
		self.A = lower_bound
		self.B = upper_bound

		self.cycle_dict = dict()
		self.populate_cycles()

		self.count_pairs()

	def populate_cycles(self):
		for i in range(self.A, self.B + 1):
			string = str(i)
			double_string = '{0}{0}'.format(string)
			length = len(string)
			for i in range(length):
				cycled_string = double_string[i : i + length]
				if cycled_string in self.cycle_dict:
					self.cycle_dict[cycled_string] += 1
					break
			else:
				self.cycle_dict[cycled_string] = 1

	def count_pairs(self):
		total_count = 0
		for k, v in self.cycle_dict.iteritems():
			if v <= 1:
				pass
			else:
				total_count += (v * (v - 1)) / 2
		self.answer = total_count

	def get_answer(self):
		return self.answer

input_file = '/tmp/03_recycled_large.in'
output_file = '/tmp/03_recycled_large.out'

class InputReader(object):

    def __init__(self, input_file, output_file):
        self.input = input_file
        self.input_buffer = []

        self.output = output_file
        self.output_buffer = []

    def run(self):
        self.initialize()
        self.generate_answer()
        self.write_output()

    def initialize(self):
        with open(self.input, 'r') as f:
            for line in f:
                self.input_buffer.append(line)

    def generate_answer(self):
        self.case_count = int(self.input_buffer[0])
        for line in self.input_buffer[1:]:
            input_numbers = line.split(' ')
            lower_bound = int(input_numbers[0])
            upper_bound = int(input_numbers[1])

            recycler = Recycler(lower_bound, upper_bound)
            self.output_buffer.append(recycler.get_answer())

    def write_output(self):
        with open(self.output, 'w') as f:
            index = 1
            for line in self.output_buffer:
                x = 'Case #{0}: {1}\n'.format(index, line)
                f.write(x)
                index += 1

reader = InputReader(input_file, output_file)
reader.run()
