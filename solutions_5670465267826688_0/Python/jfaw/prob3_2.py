import sys
import math

i=2
j=3
k=4


multiplication={(1,1):1 ,
	(1,i):i,
	(1,j):j,
	(1,k):k,
	(i,1):i,
	(i,i):-1,
	(i,j):k,
	(i,k):-j,
	(j,1):j,
	(j,i):-k,
	(j,j):-1,
	(j,k):i,
	(k,1):k,
	(k,i):j,
	(k,j):-i,
	(k,k):-1}

index_list={"i":i,"j":j,"k":k,1:1};
reverse_index={i:"i",j:"j",k:"k",1:1};

I=i
J=j
K=k



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
	raw_variable=problem[1]
	problem_variable=[]
	repeat=int(problem[0].split(" ")[1])

	problem_variable.append(raw_variable)
	problem_variable.append(repeat)

	solve(case_num,problem_variable)

def solve(case_num,problem_variable):
	"""
	if (len(problem_variable[0])<100):
		print problem_variable
		"""
	repeat=problem_variable[1]
	value=1
	one_mul=[]
	minus_sign=False


	for i in xrange (len(problem_variable[0])):
		value=multiplication[(value,index_list[problem_variable[0][i]])]
		if (value<0):
			value=-1*value
			minus_sign=not minus_sign
		one_mul.append((value,minus_sign))
	

	all_minus_sign=False
	all_value=1
	if (value==1):
		all_value=1
		x=-1 if minus_sign else 1
		all_minus_sign= True if math.pow(x, repeat)==-1 else False
	else:
		if (repeat%2==0):
			all_value=1
			all_minus_sign=(repeat%4!=0)
		else:
			all_value=value
			x=-1 if minus_sign else 1
			y= -1 if (((repeat-1)%4)!=0) else 1
			all_minus_sign= True if (math.pow(x, repeat)*y==-1) else False

	if (all_value!=1 or all_minus_sign!=True):
		print_ans(case_num,"NO")
		return


	first_index=-1
	repeat_index=0

	value=1
	minus_sign=False
	
	for index  in xrange(min(6,repeat)):
		for i in xrange (len(problem_variable[0])):
			value=multiplication[(value,index_list[problem_variable[0][i]])]
			if (value<0):
				value=-1*value
				minus_sign=not minus_sign
			if value==I and minus_sign==False:
				first_index=i
				repeat_index=index
				break
		if first_index!=-1:
			break



	if first_index==-1:
		print_ans(case_num,"NO")
		return
	right_problem=problem_variable[0][first_index+1:]
	for index in xrange(min(6,repeat-(repeat_index+1))):
		right_problem=right_problem+problem_variable[0]


	value=1
	minus_sign=False

	for i in xrange (len(right_problem)):
		value=multiplication[(value,index_list[right_problem[i]])]
		if (value<0):
			value=-1*value
			minus_sign=not minus_sign
		if value==J and minus_sign==False:
			print_ans(case_num,"YES")
			return
	
	print_ans(case_num,"NO")
	return



def main():
	input_file=sys.argv[1]
	input_processor(input_file)


if __name__=="__main__":
	main()

