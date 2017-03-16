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
    class_count = scanner.next_int()
    r = [map(int, scanner.next_line().split()[1:])
         for i in range(class_count)]
    return [[i - 1 for i in x] for x in r]

def solver_function(case):
    edges = []
    nodes = [[] for i in case]
    for (i, ns) in enumerate(case):
        for n in ns:
            edges.append((i, n))
    while True:
        leaves = set(a for (a, b) in edges)
        for (a, b) in edges:
            leaves.discard(b)
                
        for (a, b) in edges:
            if a in leaves:
                nodes[b].append(a)
                nodes[b].extend(nodes[a])
                if len(set(nodes[b])) != len(nodes[b]):
                    return 'Yes'

        e1 = [(a, b) for (a, b) in edges if a not in leaves]
        if e1 == edges:
            break
        edges = e1
                
    return 'No'

if __name__ == '__main__':
    main('sample.in')
    with open('small.out', 'w') as out: main('small.in', out)
    print 'Done'


