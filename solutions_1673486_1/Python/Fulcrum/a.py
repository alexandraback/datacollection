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

def calculate_average(length, correct_probability, typed_length):
    return correct_probability * (length - typed_length + 1) + \
        (1 - correct_probability) * (2 * length - typed_length + 2)

def solve(length, probabilities):
    averages = [
        float(length + 2), # Giving up
        calculate_average(length, reduce(float.__mul__, probabilities, 1.), len(probabilities)), # Trying
    ]

    product = 1.
    for i, backspaces_count in enumerate(xrange(len(probabilities), 0, -1)):
        averages.append(calculate_average(length, product, i) + backspaces_count)
        product *= probabilities[i]

    return '%.6f' % min(averages)

def main():
    answers = (solve(length, probabilities) for length, probabilities in input())
    output(answers)

if __name__ == '__main__':
    main()