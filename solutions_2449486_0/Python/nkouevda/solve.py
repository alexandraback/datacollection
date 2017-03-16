# Nikita Kouevda
# 2013/04/12


def main():
    import sys

    if len(sys.argv) != 2:
        print('Please specify an input file')
        sys.exit(1)

    with open(sys.argv[1], 'r') as in_file:
        content = in_file.read().strip()

    lines = content.split('\n')
    cases, i, rows, j = [[] for i in range(int(lines[0]))], -1, 0, 0

    for line in lines[1:]:
        if j == rows:
            j, rows = 0, int(line.split()[0])
            i += 1
        else:
            cases[i].append([int(mm) for mm in line.split()])
            j += 1

    for case_num, case in enumerate(cases):
        row_max = [max(row) for row in case]
        col_max = [max(row[j] for row in case) for j in range(len(case[0]))]

        possible = 'YES'

        for i in range(len(case)):
            for j in range(len(case[i])):
                if case[i][j] < row_max[i] and case[i][j] < col_max[j]:
                    possible = 'NO'
                    break

            if possible == 'NO':
                break

        print('Case #{0}: {1}'.format(case_num + 1, possible))


if __name__ == '__main__':
    main()
