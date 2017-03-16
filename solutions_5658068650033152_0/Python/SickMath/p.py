import sys
import StringIO
import math

def memfile(test_data):
    out = StringIO.StringIO()
    out.write(test_data)
    out.seek(0)
    return out

test_data = '''2
4 5 8
3 5 11
'''

class Shape():
    def __init__(self, N, M, h, w, stones):
        self.N = N
        self.M = M
        self.h = h
        self.w = w
        self.flip = 1
        self.stones = stones
    
    def expand(self):
        if self.flip == 1:
            self.exp_horizontally()
        elif self.flip == -1:
            self.exp_vertcally()
        self.flip *= -1
    
    def exp_horizontally(self):
        if (self.w - 1) < self.N:
            self.w += 1
            self.stones += 2
    
    def exp_vertcally(self):
        if (self.h - 1) < self.M:
            self.h += 1
            self.stones += 2
    
    def area(self):
        return self.w * self.h - 4

def solve(N, M, K):
    if K <= 4:
        return K
    # I can assume that one of M and N is > 1,
    # otherwise is N = M = 1 and K is bound to < 4.
    elif N == 1 or M == 1:
        return K
    else:
        shape = Shape(N, M, 3, 3, 4)
    
    while shape.area() < K:
        shape.expand()
    return shape.stones

#solve(4, 5, 8)
#solve(3, 5, 11)

infile = open(sys.argv[1]) if len(sys.argv) > 1 else memfile(test_data)

def write_solution(infile):
    infile.readline()
    out = []
    for cnt, line in enumerate(infile):
        [N, M, K] = map(int, line.split())
        res = solve(N, M, K)
        out.append('Case #%s: %s' % (cnt+1, res))
    f = open('out.txt', 'w')
    f.write('\n'.join(out) + '\n')
    f.close()

write_solution(infile)
