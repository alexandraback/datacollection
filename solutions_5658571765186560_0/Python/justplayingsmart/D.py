##input = open('D-sample-input.txt', 'r')
##output = open('D-sample-output.txt', 'w')

input = open('D-small-attempt1.in', 'r')
output = open('D-small.out', 'w')

##input = open('D-large.in', 'r')
##output = open('D-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def solve(X, R, C):
    if (R * C) % X != 0:
        return "RICHARD"
    if X > max(R, C):
        return "RICHARD"
    if (X + 1) / 2 > R or (X + 1) / 2 > C:
        return "RICHARD"
    if (R, C) == (2, 4) or (R, C) == (4, 2):
        if X == 4:
            return "RICHARD"
    return "GABRIEL"

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        X, R, C = read_ints()
        solution = solve(X, R, C)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
