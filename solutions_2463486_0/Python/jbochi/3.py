import itertools

pg = set([])

def p(i):
    s = str(i)
    return s == s[::-1]

def b(i):
    return p(i) and p(i ** 2)

pg = list((i ** 2) for i in xrange(1000) if b(i))

def solve(a, b):
    return len(filter(lambda i: i in pg, xrange(a, b + 1)))

with open("input3.txt") as f:
    file_lines = f.readlines()
    file_lines = map(lambda l: l.strip(), list(file_lines))
    l = 0
    for i in range(int(file_lines[0])):
        l += 1
        a, b = map(int, file_lines[l].split(' '))
        print "Case #%d: %s" % (i + 1, solve(a, b))
