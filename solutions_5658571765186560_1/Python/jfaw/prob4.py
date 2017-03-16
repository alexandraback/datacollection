import sys
import math

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
	num_of_lines=1
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
	raw_variable=problem[0].split(" ")
	problem_variable=[]
	for i in xrange(len(raw_variable)):
		problem_variable.append(int(raw_variable[i]))
	solve(case_num,problem_variable)

def solve(case_num,problem_variable):
	#print problem_variable
	x=problem_variable[0]
	r=problem_variable[1]
	c=problem_variable[2]

	if (x>r and x>c):
		print_ans(case_num,"RICHARD")
		return
	
	if (x>=7):
		print_ans(case_num,"RICHARD")
		return

	if ((r*c)%x!=0):
		print_ans(case_num,"RICHARD")
		return


	if (x>=(min(r+1,c+1)*2-1)):
		print_ans(case_num,"RICHARD")
		return

	if (x<(min(r,c)*2-1)):
		print_ans(case_num,"GABRIEL")
		return

	if (x<=3):
		print_ans(case_num,"GABRIEL")
		return

	if (x==4):
		if (min(r,c)>=3):
			print_ans(case_num,"GABRIEL")
			return

		else:
			print_ans(case_num,"RICHARD")
			return


	if (x==5):
		if (min(r,c)<=2):
			print_ans(case_num,"RICHARD")
			return
		if (min(r,c)==3):
			if max(r,c)>=10:
				print_ans(case_num,"GABRIEL")
				return
			else:
				print_ans(case_num,"RICHARD")
				return


	if (x==6):
		if (min(r,c)<=3):
			print_ans(case_num,"RICHARD")
			return
		else:
			print_ans(case_num,"GABRIEL")
			return
	print_ans(case_num,"UNEXPECTED")
	return




def main():
	input_file=sys.argv[1]
	input_processor(input_file)


if __name__=="__main__":
	main()







