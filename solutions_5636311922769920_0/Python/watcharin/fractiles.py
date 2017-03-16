import sys

def solve(case, k, c, s):
    # TODO Solve the problem
    targets = list()
    spot = 1

    if c == 1:
        targets = range(1, k + 1)
    else:
        for i in range(k):
            targets.append(spot)

            spot += k + 1

    rv = [ str(x) for x in targets ]

    print 'Case #%d: %s' % (case, " ".join(rv))

### Convert the input file into a list of strings ###
in_file = sys.argv[1]

with open(in_file, "r") as f:
    data = f.read()

lines = data.splitlines()
### Convert the input file into a list of strings ###

### Interpret the arguments ###
cases = int(lines.pop(0))

for i in range(1, cases + 1):
    line = lines.pop(0)

    k, c, s = line.split()

    solve(i, int(k), int(c), int(s))
### Interpret the arguments ###
