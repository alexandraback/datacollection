with open('D-small-attempt1.in', 'r') as file_in:
    lines = file_in.readlines()

t = int(lines[0])
with open('D.out', 'w') as file_out:
    for case in range(1, t + 1):
        k, c, s = map(int, lines[case].strip().split())
        if c > 1:
            result = [i * (k ** (c - 1)) + i + 1 for i in range(k)]
        else:
            result = [i + 1 for i in range(k)]
        print('Case #{}: {} (kcs = {} {} {})'.format(case, ' '.join(str(r) for r in result), k, c, s))
        file_out.write('Case #{}: {}\n'.format(case, ' '.join(str(r) for r in result)))