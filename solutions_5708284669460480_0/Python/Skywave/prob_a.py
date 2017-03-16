from itertools import *


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

in_file = open('B-small-attempt0.in', 'r')
out_file = open('out.txt', 'w')

total_case_count = int(in_file.readline())

for i in range(total_case_count):
    print(i)

    length_a, length_b, real_length = [int(x) for x in in_file.readline().split()]
    key_input = in_file.readline()[:-1]
    target_input = in_file.readline()[:-1]

    bt = [-1] * real_length
    cursor = 0
    strings = []

    while cursor >= 0:
        if cursor == real_length:
            new_string = ''

            for j in bt:
                new_string += key_input[j]

            strings.append(new_string)
            cursor -= 1

        bt[cursor] += 1

        if bt[cursor] < length_a:
            cursor += 1
        else:
            bt[cursor] = -1
            cursor -= 1

    correct = 0

    for j in strings:
        for k in range(real_length - length_b + 1):
            new_string = j[k:k+length_b]
            if new_string == target_input:
                correct += 1

    temp_length = length_b

    if target_input[0] == target_input[-1] and temp_length != 1:
        temp_length -= 1

    should_have = real_length // temp_length

    if correct == 0:
        should_have = 0

    out_file.write('Case #{}: {}\n'.format(i + 1, should_have - correct / len(strings)))

in_file.close()
out_file.close()