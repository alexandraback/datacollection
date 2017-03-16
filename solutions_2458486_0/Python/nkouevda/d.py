# Nikita Kouevda
# 2013/04/13

import sys
import threading


cache = {}


def solve(keys, chests):
    if len(chests) == 0:
        return ()

    if keys not in cache:
        cache[keys] = {}

    if chests not in cache[keys]:
        for i, chest in enumerate(chests):
            if chest[1] in keys:
                j = keys.index(chest[1])
                new_chests = chests[:i] + chests[i + 1:]
                new_keys = tuple(sorted(keys[:j] + keys[j + 1:] + chest[2]))
                solution = solve(new_keys, new_chests)

                if solution is not None:
                    cache[keys][chests] = (chest[0],) + solution
                    break

        if chests not in cache[keys]:
            cache[keys][chests] = None

    return cache[keys][chests]


def multithread_cases(pairs):
    while len(pairs) > 0:
        case_num, case = pairs.pop()

        solution = solve(tuple(sorted(case[0])), tuple(sorted(case[1])))

        if solution is None:
            output = 'IMPOSSIBLE'
        else:
            output = ' '.join(str(x) for x in solution)

        print('Case #{0}: {1}'.format(case_num + 1, output))


def main():
    if len(sys.argv) != 2:
        print('Please specify an input file')
        sys.exit(1)

    with open(sys.argv[1], 'r') as in_file:
        content = in_file.read().strip()

    lines = content.split('\n')
    cases, i, rows, j = [None for i in range(int(lines[0]))], -1, 0, 0

    for line in lines[1:]:
        if j == rows:
            rows, j = int(line.split()[1]), 0
            i += 1
            cases[i] = [None, []]
        elif cases[i][0] is None:
            cases[i][0] = tuple(int(key) for key in line.split())
        else:
            required, _, *contents = line.split()
            cases[i][1].append(
                (j + 1, int(required), tuple(int(key) for key in contents)))
            j += 1

    pairs = list(enumerate(cases))

    for i in range(8):
        threading.Thread(target=multithread_cases, args=(pairs,)).start()


if __name__ == '__main__':
    main()
