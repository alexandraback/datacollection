# Nikita Kouevda
# 2013/04/12

with open('input.txt', 'r') as in_file:
    content = in_file.read().strip()

lines = content.split('\n')
num_cases, lines = int(lines[0]), lines[1:]
cases = [[] for i in range(num_cases)]
group = 0

for line in lines:
    if line == '':
        group += 1
    else:
        cases[group].append(line)

for i, case in enumerate(cases):
    compact = ''.join(''.join(row) for row in case)
    status = 'Game has not completed' if '.' in compact else 'Draw'
    tests = {row for row in case}

    for j in range(len(case)):
        tests.add(case[0][j] + case[1][j] + case[2][j] + case[3][j])

    tests.add(case[0][0] + case[1][1] + case[2][2] + case[3][3])
    tests.add(case[0][3] + case[1][2] + case[2][1] + case[3][0])

    for test in tests:
        if '.' in test or 'X' in test and 'O' in test:
            continue

        status = 'X won' if 'X' in test else 'O won'
        break

    print('Case #{0}: {1}'.format(i + 1, status))
