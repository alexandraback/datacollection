INPUT_FILE = 'input_C.txt'
OUTPUT_FILE = 'output_C.txt'

def read_cases(input_file):
    lines = None
    with open(input_file, 'r') as f:
        lines = f.readlines()
    cases = []
    num_cases = int(lines[0])
    for i in range(1, 2 * num_cases + 1, 2):
        X = int(lines[i].split()[1])
        temp_str = lines[i + 1]
        temp_str = temp_str[0: len(temp_str) - 1]
        cases.append((X, temp_str))
    return cases

MUL_TABLE = {
    '11': '1',
    '1i': 'i',
    '1j': 'j',
    '1k': 'k',

    'i1': 'i',
    'ii': '-1',
    'ij': 'k',
    'ik': '-j',

    'j1': 'j',
    'ji': '-k',
    'jj': '-1',
    'jk': 'i',

    'k1': 'k',
    'ki': 'j',
    'kj': '-i',
    'kk': '-1'}

def mul(arg1, arg2):
    sign = 0
    if arg1[0] == '-':
        sign += 1
        arg1 = arg1[-1]
    if arg2[0] == '-':
        sign += 1
        arg2 = arg2[-1]
    args = ''.join((arg1, arg2))
    out = MUL_TABLE[args]
    if sign % 2 != 0:
        if out[0] == '-':
            out = out[1:]
        else:
            out = ''.join(('-', out))
    return out

def get_ssa(temp_str):
    ssa = [''] * len(temp_str)
    ssa[0] = temp_str[0]
    for i in range(1, len(temp_str)):
        ssa[i] = mul(ssa[i - 1], temp_str[i])
    return ssa

def get_rev_ssa(temp_str):
    rev_ssa = [''] * len(temp_str)
    rev_ssa[-1] = temp_str[-1]
    for i in range(len(temp_str) - 2, -1, -1):
        rev_ssa[i] = mul(temp_str[i], rev_ssa[i + 1])
    return rev_ssa[::-1]

def solve_case(case):
    full_str = case[1] * case[0]
    if len(full_str) < 3:
        return 'NO'
    ssa = get_ssa(full_str)
    if ssa[-1] != '-1':
        return 'NO'
    rev_ssa = get_rev_ssa(full_str)

    full_str_len = len(full_str)
    for i in range(len(ssa)):
        if ssa[i] == 'i':
            for j in range(len(rev_ssa)):
                if i + j + 2 >= full_str_len:
                    break
                if rev_ssa[j] == 'k':
                    should_be_j = mul('-i', ssa[full_str_len - (j + 1) - 1])
                    if should_be_j == 'j':
                        return 'YES'
    return 'NO'

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
    #solve_case((6, 'ji'))
    write_solutions(solutions, OUTPUT_FILE)

