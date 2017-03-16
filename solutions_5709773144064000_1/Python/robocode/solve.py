
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
    numbers = [float(x) for x in input.split()]
    numbers.reverse()

    cases_count = numbers.pop()

    cases =[]
    for i in xrange(int(cases_count)):
        farm_cost = numbers.pop()
        farm_throughput = numbers.pop()
        goal = numbers.pop()
        cases.append((farm_cost, farm_throughput, goal))

    assert(len(numbers) == 0)

    return cases

def solve(case):
    farm_cost, farm_throughput, goal = case
    return solve_(farm_cost, farm_throughput, goal)

##def solve_(farm_cost, farm_throughput, goal, cookies_per_second):
##    time_to_goal = goal / cookies_per_second
##    time_to_farm = farm_cost / cookies_per_second
##
##    next_cps = cookies_per_second + farm_throughput
##
##    time_next_cps = time_to_farm + goal / next_cps
##
##    if time_next_cps < time_to_goal:
##        return time_to_farm + solve_(farm_cost, farm_throughput, goal, next_cps)
##    else:
##        return time_to_goal

# optimized non-recursive version
def solve_(farm_cost, farm_throughput, goal):
    cookies_per_second = 2.0
    time_spent = 0.0

    while True:
        time_to_goal = goal / cookies_per_second
        time_to_farm = farm_cost / cookies_per_second

        next_cps = cookies_per_second + farm_throughput

        time_next_cps = time_to_farm + goal / next_cps

        if time_next_cps < time_to_goal:
            cookies_per_second = next_cps
            time_spent = time_spent + time_to_farm
        else:
            return time_spent + time_to_goal

def format_solution(solution, index):
    format = 'Case #%d: %.7f'
    return format % (index + 1, solution)

if __name__ == '__main__':
    main()
