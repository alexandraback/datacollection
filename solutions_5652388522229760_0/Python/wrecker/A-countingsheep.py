from codejam import *

def read_file(f):
    case = read_int(f)
    return case

def solver(case):
    if case == 0:
        return 'INSOMNIA'
    check_digits = [0]*10
    curr = 0
    while sum(check_digits) < 10:
        curr += case
        n = curr
        while n > 0:
            r = n%10
            check_digits[r] = 1
            n = n//10
    return curr

solve('A-small-attempt0', read_file, solver)
