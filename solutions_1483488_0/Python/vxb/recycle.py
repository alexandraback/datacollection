from collections import deque

num_lines = int(raw_input(''))
lines = list()
for i in range(num_lines):
    lines.append(raw_input(''))

for case, line in enumerate(lines):
    lower, upper = map(int, line.split())
    pairs = list()
    for item in range(lower, upper+1):
        rep = deque(str(item))
        # shoul rotate less than lg n times
        for j in range(len(rep)-1):
            rep.rotate(1)
            new = int("".join(rep))
            # don't want to match ourselves
            if item != new and lower <= new and new <= upper:
                pairs.append((item, new))
    # bit of a misnomer, I'm doubling up the pairs
    unique = len(set(sorted(pairs)))
    print "Case #{0}: {1}".format(case+1, unique/2)

