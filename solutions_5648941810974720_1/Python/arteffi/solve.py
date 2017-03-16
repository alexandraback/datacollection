from collections import Counter

INPUT_PATH = 'large.in'

def main():
    test_cases = parse_input(INPUT_PATH)
    solutions = []
    for i, test_case in enumerate(test_cases):
        print('-' * 10)
        print('Test case', i)
        solution = solve(test_case)
        print(test_case, '->', solution)
        solutions.append(solution)
    output_solutions(solutions)


def parse_input(path):
    with open(path) as f:
        n = int(f.readline())
        lines = f.read().split()
    test_cases = [line.strip() for line in lines]
    assert n == len(test_cases)
    return test_cases


def output_solutions(solutions):
    with open('output', 'w') as f:
        for i, solution in enumerate(solutions, 1):
            f.write('Case #{i}: {result}\n'.format(i=i, result=solution))


def solve(string):
    bounding_letters = [
        ("ZERO", "Z", '0'),
        ("TWO", "W", '2'),
        ("SIX", "X", '6'),
        ("FOUR", "U", '4'),
        ("FIVE", "F", '5'),
        ("SEVEN", "S", '7'),
        ("EIGHT", "G", '8'),
        ("NINE", "I", '9'),
        ("THREE", "H", '3'),
        ("ONE", "O", '1')]
    letters = Counter(string)
    counts = Counter()
    for number, bounding_letter, digit in bounding_letters:
        n = letters[bounding_letter]
        subtract = Counter(number * n)
        letters -= subtract
        counts[digit] = n
        #print(number, bounding_letter, digit, 'n =', n)
        #print(letters)
    seq = ''.join(digit * counts[digit] for digit in '0123456789')
    return seq


if __name__ == '__main__':
    main()
