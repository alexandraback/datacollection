def parse(input_lines):
    n_cases = int(input_lines.pop(0))
    cases = []

    for i in range(0, len(input_lines)):
        if not input_lines[i]:
            continue
        cases.append(input_lines[i].split(' '))

    return n_cases, cases

def solve_case(case):
    c, f, x = [float(i) for i in case]    
    r = 2

    if c > x:
        return x / r

    t = 0
    while True:
        buy = x / (r + f)
        wait = (x - c) / r

        if buy < wait:
            t += c / r
            r += f
        else:
            t += x / r
            return t
            
def solve(input_file):
    with open(input_file + '.in', 'r') as f:
        input_lines = f.read().split('\n')

    n_cases, cases = parse(input_lines)
    if n_cases != len(cases):
        raise ValueError('Unmatched cases!')

    solution = []

    for i in range(0, n_cases):
        answer = 'Case #%s: %0.7f' % (i+1, round(solve_case(cases[i]), 7))
        solution.append(answer)

    with open(input_file + '.out', 'w') as f:
        for line in solution:
            f.write('%s\n' % line)        

if __name__ == '__main__':
    solve('B-small-attempt0')
    #solve('problem')
    #pass

