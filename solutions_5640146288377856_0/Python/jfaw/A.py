import math
import sys

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

    """Edit start_index here"""
    start_index=1
    case_num=1
    
    """constant line num"""
    for i in xrange(0,case_nums):
        start=(i*num_of_lines)+start_index
        problem=data[start:start+num_of_lines]
        process_input_case(case_num,problem)
        case_num+=1

    """ non constant line num"""

    """
    cur_line=start_index
    for i in xrange(0,case_nums):
        num_of_lines=
        start=
        problem=data[start:start+num_of_lines]
        process_input_case(case_num,problem)
        case_num+=1
        cur_line=start+num_of_lines
    """


def process_input_case(case_num,problem):
    """Process raw input into apropriate type"""
    problem_variable=problem[0].split(" ")
    for i in xrange(len(problem_variable)):
        problem_variable[i]=int (problem_variable[i])
    solve(case_num, problem_variable)

def solve(case_num,problem_variable):
    R=problem_variable[0]
    C=problem_variable[1]
    W=problem_variable[2]
    solution=0
    if W==C:
        solution=W
    else :
        solution=W+((C-1)/W)
    if R>1:
        solution+= (C/W)
    print_ans(case_num, solution)



def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()