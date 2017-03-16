from sys import stdin

data = stdin.readlines()

for case, line in enumerate(data[1:], 1):
    pancakes = line[:-1] + '+'
    print('Case #{}: {}'.format(case, pancakes.count('+-')+pancakes.count('-+')))
