from itertools import product


def read_ints(file):
    line = file.readline().strip().split()
    result = tuple(map(int, line))
    if len(result) == 1:
        result = result[0]
    return result


def input():
    filename = __file__.split('.')[0] + '.in'
    with open(filename) as file:
        tests_count = int(file.readline().strip())

        for test_index in xrange(tests_count):
            k, l, s = read_ints(file)
            keyboard = file.readline().strip()
            target = file.readline().strip()
            yield keyboard, target, s


def output():
    filename = __file__.split('.')[0] + '.out'
    with open(filename, 'w') as file:
        i = 0
        while True:
            value = (yield)
            if value is None:
                return

            i += 1

            value = '%.7f' % value
            value = value.rstrip('0')
            if value.endswith('.'):
                value += '0'

            file.write('Case #%d: %s\n' % (i, value))


def count(string, substring):
    index = string.find(substring)
    result = 0
    while index != -1:
        result += 1
        index = string.find(substring, index + 1)

    return result


def solve(keyboard, target, s):
    for key in target:
        if key not in keyboard:
            return 0.

    max_overlap = 0
    for shift in xrange(1, len(target)):
        if target[:shift] == target[(-shift):]:
            max_overlap = shift

    max_occurences = 1 + (s - len(target)) / (len(target) - max_overlap)

    keeped_bananas = []

    for attempt in product(keyboard, repeat=s):
        attempt = ''.join(attempt)
        occurences = count(attempt, target)
        keeped_bananas.append(max_occurences - occurences)

    return sum(keeped_bananas) / float(len(keeped_bananas))


def main():
    results = output()
    results.next()

    for data in input():
        results.send(solve(*data))

    results.close()


if __name__ == '__main__':
    main()
