import sys

def digits(n):
    s = str(n)
    rv = set()

    for c in s:
        rv.add(int(c))

    return rv

def solve(case, n):
    answer = 'INSOMNIA'
    cur = n

    # TODO Solve the problem
    if n > 0:
        remaining = set(range(0, 10))

        while remaining and cur < 2000000000:
            remaining = remaining.difference(digits(cur))

            answer = cur
            cur += n

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
    n = int(lines.pop(0))

    solve(i, n)
### Interpret the arguments ###
