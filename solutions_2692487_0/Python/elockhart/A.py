from sys import *

def write(msg):
    stdout.write(msg)
    fo.write(msg)

def writeln(msg):
    write(str(msg) + '\n')

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def readstr():
    return fi.readline().rstrip()

fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])
fi = open(fni, 'r')
fo = open(fno, 'w')

def solve(a, l):
    if len(l) == 0: return 0
    if a > l[0]: return solve(a + l[0], l[1:])
    elif len(l) == 1: return 1
    elif a == 1: return 99999999999
    else:
        d = 0
        while a <= l[0]:
            d = d + 1
            a = a + (a-1)
        return d + solve(a, l)

num_cases = readint()
for case in range(1, 1+num_cases):
    (A, N) = readints()
    m = sorted(readints())
    best = solve(A, m)
    for d in range(1, N+1):
        this = d + solve(A, m[:-d])
        if this < best: best = this
    writeln("Case #%d: %d" % (case, best))

  

