import sys

def solve(A, B):
    digits = len(str(A))
    scale = 10 ** (digits - 1)
    def count(i):
        ii = i
        c = 0
        for r in range(digits - 1):
            ii = (ii / 10) + (ii % 10) * scale
            if i == ii:
                break
            elif i < ii <= B:
                c += 1
        return c
    return sum(map(count, range(A, B+1)))

with open(sys.argv[1]) as f:
    for index, case in enumerate(filter(None, f.read().split('\n')[1:])):
        case = map(int, case.split())
        A = case[0]
        B = case[1]
        result = solve(A, B)
        print 'Case #{0}: {1}'.format(index + 1, result)
