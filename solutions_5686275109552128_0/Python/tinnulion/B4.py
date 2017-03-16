import math
import heapq

INPUT_FILE = 'input_B.txt'
OUTPUT_FILE = 'output_B.txt'

def read_cases(input_file):
    lines = None
    with open(input_file, 'r') as f:
        lines = f.readlines()
    cases = []
    num_cases = int(lines[0])
    for i in range(1, 2 * num_cases + 1, 2):
        cases.append(lines[i + 1])
    return cases

def parse_case(case):
    items = case.split()
    state = []
    for i in range(len(items)):
        state.append(-int(items[i]))
    heapq.heapify(state)
    return state

def rec_solver(state):
    if state[0] == -3:
        return 3
    if state[0] == -2:
        return 2
    if state[0] == -1:
        return 1

    # Wait.
    new_state = list(state)
    for i in range(len(new_state)):
        new_state[i] += 1
    current_result = rec_solver(new_state) + 1

    # Move.
    top_el = -heapq.heappop(state)
    for i in range(2, top_el // 2 + 1):
        new_state = list(state)
        heapq.heappush(new_state, -i)
        heapq.heappush(new_state, -(top_el - i))

        result_2 = rec_solver(new_state) + 1

        current_result = min(result_2, current_result)

    heapq.heappush(state, top_el)

    return current_result

def solve_case(case):
    state = parse_case(case)

    result = rec_solver(state)
    return result

def solve(cases):
    solutions = []
    for i in range(len(cases)):
        solution = solve_case(cases[i])
        solutions.append(solution)
        print('Done case #', i)
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
    #solve_case('5 6 7 7')
    write_solutions(solutions, OUTPUT_FILE)

