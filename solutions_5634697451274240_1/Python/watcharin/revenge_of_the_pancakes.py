import sys

def solve(case, stack):
    answer = 0
    prev = '0'

    # TODO Solve the problem
    for c in stack:
        if prev == '0':
            prev = c
        elif c != prev:
            answer += 1
            prev = c

    if prev == '-':
        answer += 1

    print 'Case #%d: %s' % (case, answer)

### Convert the input file into a list of strings ###
in_file = sys.argv[1]

with open(in_file, "r") as f:
    data = f.read()

lines = data.splitlines()
### Convert the input file into a list of strings ###

### Interpret the arguments ###
cases = int(lines.pop(0))

for i in range(1, cases + 1):
    stack = lines.pop(0)

    solve(i, stack)
### Interpret the arguments ###
