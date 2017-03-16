import sys

def solve(case, k, c, s):
    # TODO Solve the problem
    targets = list()

    if c == 1 and s < k:
        return "IMPOSSIBLE"
    elif c > 1 and s < (k + 1) / 2:
        return "IMPOSSIBLE"

    off = k / 2
    spot = 1 + off

    if c == 1:
        targets = range(1, k + 1)
    else:
        for i in range(s):
            targets.append(spot)

            spot += k + 1

    rv = [ str(x) for x in targets ]
    return " ".join(rv)

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

    answer = solve(i, int(k), int(c), int(s))

    print 'Case #%d: %s' % (i, answer)
### Interpret the arguments ###
