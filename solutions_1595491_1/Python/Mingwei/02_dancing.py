class DancingEngine(object):

	def __init__(self, score_list, surprise_count, threshold):
		self.score_list = score_list
		self.surprise_count = int(surprise_count)
		self.threshold = int(threshold)

		self.dancers = []
		self.process()

	def process(self):
		for score in self.score_list:
			dancer = Dancer(int(score))
			self.dancers.append(dancer)
		count_not_surprising = len([d for d in self.dancers if d.make_best_not_surprising(self.threshold)])
		count_only_by_surprising = len([d for d in self.dancers if d.make_best_only_by_surprising(self.threshold)])
		self.answer = count_not_surprising + min(count_only_by_surprising, self.surprise_count)

	def get_answer(self):
		return self.answer


class Dancer(object):

	def __init__(self, total_score):
		self.total_score = total_score
		self.generate_best_scores()

	def make_best_not_surprising(self, threshold):
		return self.best_not_surprising >= threshold

	def make_best_only_by_surprising(self, threshold):
		return not self.make_best_not_surprising(threshold) and self.best_surprising >= threshold

	def generate_best_scores(self):
		floor_average_score = self.total_score / 3
		if self.total_score % 3 == 0:
			self.best_not_surprising =  floor_average_score
			if floor_average_score > 0:
				self.best_surprising = floor_average_score + 1
			else:
				self.best_surprising = floor_average_score
		elif self.total_score % 3 == 1:
			self.best_not_surprising =  floor_average_score + 1
			self.best_surprising = floor_average_score + 1
		else:
			self.best_not_surprising =  floor_average_score + 1
			self.best_surprising = floor_average_score + 2


input_file = '/tmp/02_dancing_large.in'
output_file = '/tmp/02_dancing_large.out'

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
            number_dancers = int(input_numbers[0])
            number_surprising = int(input_numbers[1])
            threshold = int(input_numbers[2])
            score_list = input_numbers[3:]

            engine = DancingEngine(score_list, number_surprising, threshold)
            self.output_buffer.append(engine.get_answer())

    def write_output(self):
        with open(self.output, 'w') as f:
            index = 1
            for line in self.output_buffer:
                x = 'Case #{0}: {1}\n'.format(index, line)
                f.write(x)
                index += 1

reader = InputReader(input_file, output_file)
reader.run()