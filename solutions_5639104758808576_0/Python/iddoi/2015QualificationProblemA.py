import GCJInfra

class ProblemA(GCJInfra.Problem):
	def initialize_from_input(self):
		self.number_of_cases = self.input_reader.read_int()

	def solve_case(self):
		in_list = self.input_reader.read_string_list(" ")
		S_max = int(in_list[0])
		people = [int(t) for t in in_list[1]]
		accumulated_sum = 0
		max_diff = 0
		for i in xrange(1,S_max+1):
			accumulated_sum += people[i-1]
			max_diff = max(max_diff, i - accumulated_sum)
		self.results.append(str(max_diff))
		
if "__main__" == __name__:
	filename = "A-small-attempt0"
	problem_a = ProblemA(filename)
	problem_a.solve()