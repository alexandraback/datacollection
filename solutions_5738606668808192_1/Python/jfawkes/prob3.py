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
    problem = problem[0].split(" ")
    N = int(problem[0])
    J = int (problem[1])
    solve(case_num,N,J)

def solve(case_num, N, J):
    print "Case #1:"
    counter = 0
    n = 0;
    while True:
        if counter >= J:
            return
        divisor_list = []
        bin_part = str(bin(n))[2:]
        if len(bin_part) > N-2:
            return
        bin_string = "1"+ ((N-2-len(bin_part))*"0") + bin_part +"1"
        for i in xrange(2,11):
            num = int(bin_string,i)
            divisor = get_divisor(num)
            if divisor == -1 :
                continue
            divisor_list.append(divisor)
        if len(divisor_list) == 9:
            counter +=1
            print bin_string,
            print " ".join(str(x) for x in divisor_list)


        n+=1



def get_divisor(n):
    limit = 10000
    max_div = min (n, int(math.sqrt(n)+1), limit)
    for i in xrange(2,max_div+1):
        if n % i == 0:
            return i
    return -1




def main():
    input_file=sys.argv[1]
    input_processor(input_file)


if __name__=="__main__":
    main()