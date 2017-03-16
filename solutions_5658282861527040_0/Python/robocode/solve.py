import argparse

def main():
    args = parse_arguments()
    parse_and_solve(args.input, args.output)

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'),
                        nargs='?', default='input.txt', help='input file')
    parser.add_argument('output', type=argparse.FileType('w'),
                        nargs='?', default='output.txt', help='output file')

    return parser.parse_args()

def parse_and_solve(input, output):
    content = input.read()

    cases = parse_input(content)

    solutions = [solve(case) for case in cases]

    formatted_solutions = [format_solution(solution, i) for i, solution in enumerate(solutions)]
    joined_solutions = '\n'.join(formatted_solutions)

    output.write(joined_solutions)
    print joined_solutions

def parse_input(input):
    numbers = [x for x in input.split()]
    numbers.reverse()

    cases_count = int(numbers.pop())

    cases = []
    for i in xrange(cases_count):
        a = int(numbers.pop())
        b = int(numbers.pop())
        k = int(numbers.pop())
        cases.append((a, b, k))

    assert(len(numbers) == 0)

    return cases

def solve(case):
    a, b, k = case

    s = 0
    for i in xrange(a):
        for j in xrange(b):
            x = i & j
            if x < k:
                s += 1

    return s





def bin_(number):
    return bin(number)[2:]

def format_solution(solution, index):
    format = 'Case #%d: %s'
    return format % (index + 1, solution)

if __name__ == '__main__':
    main()
