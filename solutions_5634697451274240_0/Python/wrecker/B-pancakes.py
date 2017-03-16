from codejam import *

def read_file(f):
    case = read_string(f)
    return case

def solver(case):
    def flip(remaining, direction):
        while case[remaining-1] == direction and remaining > 1:
            remaining -= 1
        if remaining == 1:
            if case[0] == direction:
                return 0
            else:
                return 1
        if direction == '+':
            return flip(remaining-1, '-') + 1
        else:
            return flip(remaining-1, '+') + 1
    return flip(len(case), '+')

solve('B-small-attempt0', read_file, solver)
