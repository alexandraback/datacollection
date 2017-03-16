# Nikita Kouevda
# 2013/05/04

import sys


def get_num_ops(initial, motes, num_ops=0):
    if initial == 1:
        return num_ops + len(motes)

    remaining = []

    for mote in motes:
        if mote < initial:
            initial += mote
        else:
            remaining.append(mote)

    if len(remaining) == 0:
        return num_ops
    elif len(remaining) == 1:
        return num_ops + 1
    else:
        return min(
            num_ops + len(remaining),
            get_num_ops(initial, [initial - 1] + remaining, num_ops + 1))


def main():
    if len(sys.argv) != 2:
        print('Please specify an input file')
        sys.exit(1)

    with open(sys.argv[1], 'r') as in_file:
        content = in_file.read().strip()

    lines = content.split('\n')
    cases = []

    for first, second in zip(lines[1::2], lines[2::2]):
        cases.append((
            tuple(int(value) for value in first.strip().split()),
            tuple(int(value) for value in second.strip().split())))

    for case_num, case in enumerate(cases):
        (initial, _), motes = case

        num_ops = get_num_ops(initial, sorted(motes))

        print('Case #{0}: {1}'.format(case_num + 1, num_ops))


if __name__ == '__main__':
    main()
