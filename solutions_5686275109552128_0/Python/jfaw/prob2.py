import sys
import math
import bisect

case_nums=0
num_of_lines=1



	
def print_ans(case_num,solution):
 	print("Case #"+str(case_num)+":"),
 	print_solution(solution)

def print_solution(solution):
	"""TO DO"""
	print solution


def input_processor(filename):
	f=open(filename)
	data=f.read().split("\n")
	case_nums=int(data[0])

	"""Insert number of lines per test case here"""
	num_of_lines=2
	data_length=len(data)

	"""Edit start_index here"""
	start_index=1
	case_num=1
	

	for i in xrange(0,case_nums):
		start=(i*num_of_lines)+start_index
		problem=data[start:start+num_of_lines]
		process_input_case(case_num,problem)
		case_num+=1

def process_input_case(case_num,problem):
	"""Process raw input into apropriate type"""
	problem_variable=[]
	raw_variable=problem[1].split(" ")
	for i in xrange(int(problem[0])):
		problem_variable.append(int(raw_variable[i]))
	solve(case_num,problem_variable)



def solve(case_num,problem_variable):
	sorted_list=sorted(problem_variable)
	solution=bf_solve(sorted_list)
	print_ans(case_num,solution)

def recursive_solve(problem):
	largest_num=problem[-1]
	if largest_num<=3:
		return largest_num
	else:
		problem.pop()
		half=largest_num/2
		index=bisect.bisect_left(problem, half)
		problem.insert(index,half)
		if (largest_num%2==0):
			problem.insert(index,half)
		else:
			bisect.insort_left(problem,half+1)
		return min(largest_num,1+recursive_solve(problem))



def bf_solve(problem):
	largest_num=problem[-1]
	if largest_num<=3:
		return largest_num
	best_solution=largest_num
	for eat_num in xrange (2,best_solution):
		if eat_num>=best_solution:
			break
		solution=eat_num
		for i in xrange (len(problem)):
			num=problem[-1*(i+1)]
			if (num<=eat_num):
				break
			divide_num=num/eat_num
			if (num%eat_num==0):
				divide_num-=1
			solution+=divide_num
		if solution<best_solution:
			best_solution=solution
	return best_solution







def main():
	input_file=sys.argv[1]
	input_processor(input_file)


if __name__=="__main__":
	main()