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
    #print problem[0]
    solve(case_num, int(problem[0]))

def reverse(a):
    return int(str(a)[::-1])

def solve(case_num,problem_variable):
    N=problem_variable
    SN=str(N)
    count=0
    while True:
        SN=str(N)
        if (len(SN)==1):
            count+=N
            break
            """
        if SN[0]!='1' and SN[-1]=='1':
            N=reverse(N)

        else:
            N=N-1
        count+=1
        """
        length= len(SN)
        if int(SN[-(length/2):])==1:
            if (reverse(N)<N-1):
                N=reverse(N)
                count+=1
            else:
                N=N-1
                count+=1
        else:
            n=int(SN[-(length/2):])
            if (n>0):
                count+=(n-1)
                N-=(n-1)
            else:
                count+=1
                N=N-1

        #print N
        
    print_ans(case_num, count)



def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()