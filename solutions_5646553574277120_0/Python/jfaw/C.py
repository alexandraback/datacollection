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
    num_of_lines=2

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
    problem_variable=[]
    problem_variable.append(problem[0].split(" "))
    problem_variable.append(problem[1].split(" "))
    for i in xrange (len(problem_variable)):
        for j in xrange(len(problem_variable[i])):
            problem_variable[i][j]= int(problem_variable[i][j])
    solve(case_num, problem_variable)

def solve(case_num,problem_variable):
    C=problem_variable[0][0]
    V=problem_variable[0][2]
    avail=problem_variable[1]
    cur_max=0
    next_max=0
    current=0
    before_cur=-1
    solution=0
    while True:
        before_cur=current
        if next_max>=V:
            break
        for i in xrange(len(avail)):
            if avail[i]>current and avail[i]<=next_max+1 :
                current=avail[i]
                avail.pop(i)
                break
        if before_cur==current:
            current=next_max+1
            solution+=1
        next_max=current*C+next_max
    print_ans(case_num, solution)



def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()