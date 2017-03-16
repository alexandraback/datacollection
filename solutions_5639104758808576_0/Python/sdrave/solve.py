import sys
import numpy as np

data = open(sys.argv[1]).readlines()[1:]

def process(d):
    count, d = d.split(' ')
    count = int(count)
    assert len(d) == count + 1
    people = map(int, d)

    needed = 0
    standing = 0
    for s, p in enumerate(people):
        if p and standing < s:
            new_needed = s - standing
            needed += new_needed
            standing += new_needed
        standing += p
    return needed



with open(sys.argv[2], 'w') as f:
    for i, d in enumerate(data):
        f.write('Case #{}: {}\n'.format(i+1, process(d.strip())))
