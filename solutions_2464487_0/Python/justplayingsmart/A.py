##input = open('A-sample-input.txt', 'r')
##output = open('A-sample-output.txt', 'w')

input = open('A-small-attempt0.in-1', 'r')
output = open('A-small.out', 'w')

##input = open('A-large.in', 'r')
##output = open('A-large.out', 'w')

from decimal import *
getcontext().prec = 70

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]



def solve(r, t):
    plus = Decimal((1 - 2 * r + (4 * r ** 2 - 4 * r + 1 + 8*t)**Decimal(0.5))/4)
    return int(plus)

    




def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        r,t = read_ints()
##        if case == 1:
        solution = solve(r, t)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
