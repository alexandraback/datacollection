with open('A-large.in') as file_in:
    lines = file_in.readlines()
t = int(lines[0])
cases = list(map(int, lines[1:]))
result = []

for case in range(len(cases)):
    n = cases[case]
    multiple = n
    if n != 0:
        seen = set(str(n))
        while len(seen) < 10:
            multiple += n
            for digit in str(multiple):
                seen.add(digit)
        result.append(str(multiple))
    else:
        result.append('INSOMNIA')

with open('A.out', 'w') as file_out:
    for i in range(1, t + 1):
        print('Case #{}: {}'.format(i, result[i - 1]))
        file_out.write('Case #{}: {}\n'.format(i, result[i - 1]))