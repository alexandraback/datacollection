# Google Code Jam 2013, Round 1C, Problem B
#


import sys, re


def solve(num, x, y):
    fy, by = ('N', 'S') if y > 0 else ('S', 'N')
    fx, bx = ('E', 'W') if x > 0 else ('W', 'E')
    s = []
    if x != 0:
        s.extend([bx, fx] * (abs(x)))
    if y != 0:
        s.extend([by, fy] * (abs(y)))
    return ''.join(s)
    
            

def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in xrange(1, total+1):
            x, y = map(int, f_in.readline().strip().split(' '))
            print 'Case #{0}: {1}'.format(i, solve(i, x, y))
            

if __name__ == "__main__":
    main(sys.argv[1])
