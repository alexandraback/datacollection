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
            _, x = read_ints(file)
            string = file.readline().strip()
            yield string, x


def output():
    filename = __file__.split('.')[0] + '.out'
    with open(filename, 'w') as file:
        i = 0
        while True:
            value = (yield)
            if value is None:
                return

            i += 1
            file.write('Case #%d: %s\n' % (i, ('NO', 'YES')[value]))


def multiply_quaternions(q1, q2):
    v1, p1 = q1
    v2, p2 = q2

    rules = {
        '1': {'1': ('1', True), 'i': ('i', True), 'j': ('j', True), 'k': ('k', True)},
        'i': {'1': ('i', True), 'i': ('1', False), 'j': ('k', True), 'k': ('j', False)},
        'j': {'1': ('j', True), 'i': ('k', False), 'j': ('1', False), 'k': ('i', True)},
        'k': {'1': ('k', True), 'i': ('j', True), 'j': ('i', False), 'k': ('1', False)},
    }

    answer, positive = rules[v1][v2]
    if p1 ^ p2:
        positive = not positive

    return answer, positive


def solve(string, multiplier):
    sequence = [(s, True) for s in string]
    string_value = reduce(multiply_quaternions, sequence)
    overall_value = reduce(multiply_quaternions, [string_value] * (multiplier % 4), ('1', True))

    if overall_value != ('1', False):
        return False

    enlarged_sequence = sequence * 4

    prefix = ('1', True)

    for i, q in enumerate(enlarged_sequence, start=1):
        prefix = multiply_quaternions(prefix, q)
        if prefix == ('i', True):
            first_i = i
            break
    else:
        return False

    suffix = ('1', True)

    for i, q in enumerate(reversed(enlarged_sequence), start=1):
        suffix = multiply_quaternions(q, suffix)
        if suffix == ('k', True):
            last_k = i
            break
    else:
        return False

    if first_i + last_k > len(sequence) * multiplier:
        return False

    return True


def main():
    results = output()
    results.next()

    for string, multiplier in input():
        results.send(solve(string, multiplier))

    results.close()


if __name__ == '__main__':
    main()
