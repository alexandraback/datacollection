INPUT_FILE = 'input.txt'
OUTPUT_FILE = 'output.txt'

def read_cases(input_file):
    lines = None
    with open(input_file, 'r') as f:
        lines = f.readlines()
    cases = []
    num_cases = int(lines[0])
    for i in range(1, num_cases + 1):
        line = lines[i]
        items = line.split()
        s_max = int(items[0])
        str = items[1]
        cases.append((s_max, str))
    return cases

def solve_case(s_max, str):
    friends_to_invite = 0
    stood_up_so_far = 0
    for i in range(len(str)):
        if stood_up_so_far < i: # not enough
            friends_to_invite += i - stood_up_so_far
            stood_up_so_far = i
        num = int(str[i])
        stood_up_so_far += num
    return friends_to_invite

def solve(cases):
    solutions = []
    for i in range(len(cases)):
        solution = solve_case(cases[i][0], cases[i][1])
        solutions.append(solution)
    return solutions

def write_solutions(solutions, output_file):
    with open(output_file, 'w') as f:
        for i in range(len(solutions)):
            line = 'Case #' + str(i + 1) + ': ' + str(solutions[i]) + '\n'
            f.write(line)

if __name__ == '__main__':
    cases = read_cases(INPUT_FILE)
    solutions = solve(cases)
    write_solutions(solutions, OUTPUT_FILE)

