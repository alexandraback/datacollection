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

def do_sanity_check(item, x):
    y = x % 4
    acc = '1'
    for i in range(y):
        acc = mul(acc, item)
    result = (acc == '-1')
    return result

def solve_case(case):
    x = case[0]
    part_str = case[1]

    if len(part_str) * x < 3:
        return 'NO'

    ssa = get_ssa(part_str)
    if not do_sanity_check(ssa[-1], x):
        return 'NO'

    if x > 8:
        x = x % 4 + 4
    full_str = part_str * x

    ssa = get_ssa(full_str)

    ssa_len = len(ssa)
    for i in range(ssa_len):
        if ssa[i] == 'i':
            for j in range(i + 1, ssa_len - 1):
                if ssa[j] == 'k':
                    return 'YES'
            return 'NO'
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

