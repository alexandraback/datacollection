from solver import solver
from itertools import count

DIGIT_SET = set('0123456789')

def last_number(n):
    s = set()
    for x in count(1):
        s |= set(str(x*n))
        if s == DIGIT_SET:
            return x*n

@solver
def sheep(lines):
    n = int(lines[0])
    if n == 0:
        return 'INSOMNIA'
    return last_number(n)

if __name__ == '__main__':
    sheep.from_cli()
