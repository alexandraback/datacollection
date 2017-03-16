##input = open('C-sample-input.txt', 'r')
##output = open('C-sample-output.txt', 'w')

input = open('C-small-1-attempt0.in', 'r')
output = open('C-small-1.out', 'w')

##input = open('C-large.in', 'r')
##output = open('C-large.out', 'w')

import random

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def find_factors(M, product):
    factors = []
    while product > 1:
        for i in range(2, M+1):
            if product % i == 0:
                factors.append(i)
                product /= i
                break
    return factors


def solve(N, M, K, products):    
    factors = {2:0, 3:0,5:0}
    for i in range(K):
        product_factors = find_factors(M, products[i])
        for j in [2, 3, 5]:
            c = product_factors.count(j)
            if c > factors[j]:
                factors[j] = c
    solution = ''
    solution += ('3' * factors[3]) + ('5' * factors[5]) +\
                ('2' * (factors[2] % 2)) + ('4' * (factors[2] / 2))
    guesses = N - len(solution)
    for i in range(guesses):
        solution += str(random.randrange(2, M+1))
    return solution
    
    
            

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        R, N, M, K = read_ints()
        solution = ''
        for line in range(R):
            products = read_ints()
            small_solution = solve(N, M, K, products)
            solution += small_solution +'\n'
        solution = solution.strip()
        solution_string = "Case #%d: \n%s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
