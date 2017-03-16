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
    problem_variable = list(int(x) for x in problem[0].split(" "))
    solve(case_num,problem_variable)

def solve(case_num,problem_variable):
    K = problem_variable[0]
    C = problem_variable[1]
    S = problem_variable[2]
    if C == 1:
        if S < K:
            print_ans(case_num,"IMPOSSIBLE")
            return
        else:
            solution = " ".join(str(x) for x in xrange(1,1+K))
            print_ans(case_num, solution)
            return


    if S <= 0:
        print_ans(case_num,"IMPOSSIBLE")
        return
    if S < (K-1):
        print_ans(case_num,"IMPOSSIBLE")
        return
    if K==1:
        solution = 1
        print_ans(case_num, solution)
    else:
        solution = " ".join(str(x) for x in xrange(2,2+K-1))
        print_ans(case_num, solution)





def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()