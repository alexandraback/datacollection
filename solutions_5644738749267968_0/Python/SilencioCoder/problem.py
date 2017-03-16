from copy import deepcopy

def parse(input_lines):
    n_cases = int(input_lines.pop(0))
    cases = []

    for i in range(0, len(input_lines), 3):
        if not input_lines[i]:
            continue
        b = int(input_lines[i])
        n = [float(item) for item in input_lines[i+1].split(' ')]
        n.sort()
        k = [float(item) for item in input_lines[i+2].split(' ')]
        k.sort()
        cases.append((b, n, k))

    return n_cases, cases

def solve_case(case):
    return '%s %s' % (solve_dwar(deepcopy(case)), solve_war(deepcopy(case)))

def solve_dwar(case):
    b, n, k = case

    p = 0
    for i in range(0, b):
        n_max = max(n)
        k_max = max(k)
        if n_max > k_max:
            n.remove(n_max)
            k.remove(k_max)
            p += 1
            continue
        
        n_play = min(n)
        n.remove(n_play)

        k_max = max(k) - 0.0000001
        dn_play = n_play if n_play > k_max else k_max
        
        k_play = [item for item in k if item > dn_play]
        k_play = min(k_play) if k_play else min(k)
        k.remove(k_play)

        print n_play, dn_play, k_play, n_play > k_play

        if n_play > k_play:
            p += 1

    return p

def solve_war(case):
    b, n, k = case

    p = 0
    for i in range(0, b):
        n_play = min(n)
        n.remove(n_play)

        k_play = [item for item in k if item > n_play]
        k_play = min(k_play) if k_play else min(k)
        k.remove(k_play)

        if n_play > k_play:
            p += 1
                  
    return p

def solve(input_file):
    with open(input_file + '.in', 'r') as f:
        input_lines = f.read().split('\n')

    n_cases, cases = parse(input_lines)
    #return n_cases, cases
    if n_cases != len(cases):
        raise ValueError('Unmatched cases!')

    solution = []
    for i in range(0, n_cases):
        answer = 'Case #%s: %s' % (i+1, solve_case(cases[i]))
        solution.append(answer)

    with open(input_file + '.out', 'w') as f:
        for line in solution:
            f.write('%s\n' % line)            

if __name__ == '__main__':
    solve('D-small-attempt0')
    #solve('problem')
    #pass
