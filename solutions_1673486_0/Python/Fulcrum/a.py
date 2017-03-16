def input():
    with open('a.in') as file:
        tests_count = int(file.readline().strip())
        for i in xrange(tests_count):
            typed_length, length = tuple(int(n) for n in file.readline().strip().split())
            probabilities = [float(n) for n in file.readline().strip().split()]

            yield length, probabilities

def output(answers):
    with open('a.out', 'w') as file:
        for i, answer in enumerate(answers):
            file.write('Case #%s: %s\n' % (i + 1, answer))

def multiply(numbers, reverse=False):
    if reverse:
        return multiply(1. - n for n in numbers)
    return reduce(float.__mul__, numbers, 1.)

def calculate_average(length, probabilities):
    correct_probability = multiply(probabilities)
    return correct_probability * (length - len(probabilities) + 1) + \
        (1 - correct_probability) * (2 * length - len(probabilities) + 2)

def solve(length, probabilities):
    averages = [
        float(length + 2), # Giving up
        calculate_average(length, probabilities), # Trying
    ]

    for backspaces_count in xrange(1, len(probabilities) + 1):
        averages.append(calculate_average(length, probabilities[:-backspaces_count]) + backspaces_count)

    return '%.6f' % min(averages)

def main():
    answers = (solve(length, probabilities) for length, probabilities in input())
    output(answers)

if __name__ == '__main__':
    main()