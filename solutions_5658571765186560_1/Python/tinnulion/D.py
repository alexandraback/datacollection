INPUT_FILE = 'input_D.txt'
OUTPUT_FILE = 'output_D.txt'

def read_cases(input_file):
    lines = None
    with open(input_file, 'r') as f:
        lines = f.readlines()
    cases = []
    num_cases = int(lines[0])
    for i in range(0, num_cases):
        line = lines[i + 1]
        items = line.split()
        X = int(items[0])
        R = int(items[1])
        C = int(items[2])
        if R < C:
            R, C = C, R
        assert(R >= C)
        cases.append((X, R, C))
    return cases

def get_fuckin_answer(X, R, C):

    if X > R:
        return False
    if (R * C) % X != 0:
        return False

    if X == 1:
        return True

    if X == 2:
        if (R * C) % 2 == 0:
            return True
        return False

    if X == 3:
        if (R == 3) and (C == 2):
            return True
        if (R == 3) and (C == 3):
            return True
        if (R == 4) and (C == 3):
            return True
        if R > 4:
            return True
        return False

    if X == 4:
        if (R == 4) and (C == 3):
            return True
        if (R == 4) and (C == 4):
            return True
        if R > 4:
            return True
        return False

    if X == 5:
        return True

    if X == 6:
        return True

    return False


def solve_case(case):
    X = case[0]
    R = case[1]
    C = case[2]

    return get_fuckin_answer(X, R, C)

def solve(cases):
    solutions = []
    for i in range(len(cases)):
        solution = solve_case(cases[i])
        if solution:
            solutions.append('GABRIEL')
        else:
            solutions.append('RICHARD')
    return solutions

def write_solutions(solutions, output_file):
    with open(output_file, 'w') as f:
        for i in range(len(solutions)):
            line = 'Case #' + str(i + 1) + ': ' + str(solutions[i])
            f.write(line + '\n')
            print(line)

if __name__ == '__main__':
    cases = read_cases(INPUT_FILE)
    solutions = solve(cases)
    write_solutions(solutions, OUTPUT_FILE)

