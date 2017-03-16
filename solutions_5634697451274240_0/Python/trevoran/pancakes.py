with open('B-small-attempt0.in', 'r') as file_in, open('B.out', 'w') as file_out:
    lines = file_in.readlines()
    t = int(lines[0])

    for case in range(1, t + 1):
        # noinspection PyRedeclaration
        pancakes = lines[case].strip()
        # ignore any + pancakes at end of stack, they're irrelevant
        pancakes = pancakes.rstrip('+')

        flips = 0
        if len(pancakes) > 0:
            # at least one flip because final cake must be '-'
            flips = 1
            index = len(pancakes) - 1
            looking_for = '+'
            while index > 0:
                index -= 1
                if pancakes[index] == looking_for:
                    looking_for = '-' if looking_for == '+' else '+'
                    flips += 1
        file_out.write('Case #{}: {}\n'.format(case, flips))
        print('Case #{}: {}'.format(case, flips))
