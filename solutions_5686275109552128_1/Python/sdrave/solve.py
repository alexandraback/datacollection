import sys
import numpy as np


def process(d):
    d = d.split(' ')
    plates = np.array(map(int, d))

    def time_needed(max_height):
        specials_needed = plates / max_height + ((plates % max_height) > 0).astype(int) - 1
        return np.sum(specials_needed) + max_height

    return min(map(time_needed, range(1, np.max(plates) + 1)))


data = open(sys.argv[1]).readlines()[1:]

with open(sys.argv[2], 'w') as f:
    for i, d in enumerate(data[1::2]):
        f.write('Case #{}: {}\n'.format(i+1, process(d.strip())))
