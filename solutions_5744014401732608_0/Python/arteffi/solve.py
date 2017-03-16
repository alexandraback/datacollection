INPUT_PATH = 'small.in'

def main():
    test_cases = parse_input(INPUT_PATH)
    solutions = []
    for i, test_case in enumerate(test_cases):
        print('-' * 10)
        print('Test case', i)
        solution = solve(*test_case)
        print(test_case, '->', solution)
        solutions.append(solution)
    output_solutions(solutions)


def parse_input(path):
    with open(path) as f:
        n = int(f.readline())
        lines = f.read().split('\n')
    test_cases = [tuple(map(int, line.split())) for line in lines][:n]
    return test_cases


def output_solutions(solutions):
    with open('output', 'w') as f:
        for i, solution in enumerate(solutions, 1):
            possible, matrix = solution
            f.write('Case #{i}: {result}\n'.format(i=i, result='POSSIBLE' if possible else 'IMPOSSIBLE'))
            if possible:
                for row in matrix:
                    f.write(''.join(map(str, row)) + '\n')


def solve(b, m):
    # NOTE: b > 1
    #print('solving for:', b, m)
    max_paths = 2 ** (b - 2)
    if m > max_paths:
        return False, None
    matrix = [[(1 if j > i else 0) for j in range(b)] for i in range(b)]
    if m == max_paths:
        return True, matrix
    binary = bin(m)[2:][::-1]
    for row in range(b-1):
        if 1 <= row <= len(binary):
            matrix[row][b-1] = int(binary[row-1])
        else:
            matrix[row][b-1] = 0
    return True, matrix


if __name__ == '__main__':
    main()
