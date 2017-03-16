import re

class InputScanner(object):

    def __init__(self, filename, parse_function):
        with open(filename) as f:
            self.reversed_lines = list(reversed(f.read().split('\n')))
        self.case_count = 0
        self.total_cases = self.next_int()
        self.parse_function = parse_function

    def __iter__(self):
        for i in range(self.total_cases):
            yield self.next_case()

    def next_int(self):
        return int(self.reversed_lines.pop())
    
    def next_line(self):
        return self.reversed_lines.pop()

    def next_matrix(self):
        (h, w) = map(int, self.next_line().split())
        return tuple(tuple(self.next_line()) for i in range(h))

    def next_case(self):
        p = self.parse_function(self)
        self.case_count += 1
        return p

class Solver(object):

    def __init__(self, solver_function, input_scanner, out=None):
        self.solver_function = solver_function
        self.out = out
        self.input_scanner = input_scanner

    def solve(self):
        for case in iter(self.input_scanner):
            print >> self.out, 'Case #%s: %s' % (self.input_scanner.case_count,
                                                 self.solver_function(case))

def main(input_filename, out=None):
    input_scanner = InputScanner(input_filename, parse_function)
    Solver(solver_function, input_scanner, out).solve()


########################################################################

def parse_function(scanner):
    n, m = map(int, scanner.next_line().split())
    a = map(int, scanner.next_line().split())
    b = map(int, scanner.next_line().split())
    return (a, b)

def solver_function(case):
    bline, tline = case
    boxes = tuplize(bline)
    toys = tuplize(tline)
    return str(solve(boxes, toys))

def tuplize(li):
    return [(li[i], li[i + 1])
            for i in range(0, len(li) -1, 2)]

def solve(boxes, toys):
    if not boxes or not toys:
        return 0
    (bq, bt) = boxes[0]
    (tq, tt) = toys[0]
    if tt == bt:
        if bq < tq:
            nb = boxes[1:]
            nt = [(tq - bq, tt)] + toys[1:]
            return solve(nb, nt) + bq
        elif bq > tq:
            nb = [(bq - tq, bt)] + boxes[1:]
            nt = toys[1:]
            return solve(nb, nt) + tq
        else:
            return solve(boxes[1:], toys[1:]) + bq
    else:
        return max(solve(boxes[1:], toys), solve(boxes, toys[1:]))

if __name__ == '__main__':
    #main('sample.in')
    with open('small.out', 'w') as out: main('small.in', out)
    print 'Done'


