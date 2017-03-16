import sys
import numpy as np

def process(d):
    X, R, C = map(int, d.strip().split(' '))
    if X == 1:
        return True
    elif X == 2:
        return (R * C) % 2 == 0
    elif X == 3:
        return ((R >= 2) and (C % 3 == 0) or
                (C >= 2) and (R % 3 == 0))
    elif X == 4:
        return (R * C) % 4 == 0 and ((R >= 3 and C >= 4) or (R >= 4 and C >=3))
    else:
        raise NotImplementedError

data = open(sys.argv[1]).readlines()[1:]

with open(sys.argv[2], 'w') as f:
    for i, d in enumerate(data):
        f.write('Case #{}: {}\n'.format(i+1, 'GABRIEL' if process(d) else 'RICHARD'))
