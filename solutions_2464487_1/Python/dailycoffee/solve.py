from math import sqrt

def solve_qe(a, b, c):
    D = b * b  - 4 * a * c
    assert D > 0
    return (-b + sqrt(D)) / (2 * a)

def solve(r, t):
    black0 = (2 * r + 1)
    assert t - black0 >= 0
    r += 2
    d = 4
    return int(solve_qe(
        d,
        2 * black0 - d,
        -2 * t
    ))

def line(f):
    return [int(n) for n in f.readline().rstrip().split()]

def main(f):
    for i in range(line(f)[0]):
        r, t = line(f)
        print('Case #{}: {}'.format(i + 1, solve(r, t)))

if __name__ == '__main__':
    #with open('sample.in') as f:
        #main(f)
    import sys
    main(sys.stdin)
