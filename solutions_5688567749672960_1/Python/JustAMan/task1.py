import sys
import math

def swap(k):
    return int(''.join(reversed(str(k))))

def solve_round(n, round1, round2):
    if n <= 20:
        return n

    n_size = len(str(n))
    half1 = ''.join(reversed(str(n)))[int(round1(n_size * 0.5)):]
    half2 = str(n)[int(round2(n_size * 0.5)):]

    if int(half2) == 0:
        return solve_round(n - 1, round1, round2) + 1

    act = 0
    for size in xrange(1, n_size):
        act += 10 ** (size - size / 2) + 10 ** (size / 2) - 1
    if 10 ** (n_size - 1) == n:
        return act

    if n_size >= 2:
        counted = int('1' + '0' * (n_size - 2) + '1')
    else:
        counted = 1
    if int(half1) == 1:
        return act + int(half2)
    return act + int(half1) + int(half2)

def solve(n):
    return min(solve_round(n, math.floor, math.ceil), solve_round(n, math.ceil, math.floor))

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            N = int(inp.readline().strip())
            out.write('Case #%d: %s\n' % (t + 1, solve(N)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
