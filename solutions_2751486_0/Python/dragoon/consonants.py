import re
lines = open('data.txt').read()
output = open('output.txt', 'w')
SPLIT = re.compile(r'[aeiou]')

lines = lines.splitlines()[1:]
vowels = {'a', 'e', 'i', 'o', 'u'}

for i, line in enumerate(lines):
    case_num = i + 1
    name, n = line.split()
    n = int(n)

    n_metric = 0
    for i in range(len(name)):
        for j in range(i+1, len(name)+1):
            max_consec = len(max(SPLIT.split(name[i:j]), key=lambda x: len(x)))
            if max_consec >= n:
                n_metric += 1
    output.write('Case #{0}: {1}'.format(case_num, n_metric) + '\n')
    print 'Case #{0}: {1}'.format(case_num, n_metric)


