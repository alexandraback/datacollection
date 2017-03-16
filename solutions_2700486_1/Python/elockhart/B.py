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

def akh(N, k):
   print "at least %d heads from %d" % (k, N)
   nCr = 1
   for x in range(k): nCr = (nCr * (N-x)) / (x+1)
   count = nCr
   for x in range(k, N):
        nCr = (nCr * (N-x)) / (x+1)
        count = count + nCr
   return float(count) / float(2**N)

def completed_shells(N):
    if (N == 0): return (0, 0)
    if (N == 1): return (1, 1)
    i = 0
    while i * (2*i-1) <= N:
        i = i + 1
    comp = (i-1) * (2*i-3)
    return (i-1, comp)

num_cases = readint()
for case in range(1, 1+num_cases):
    (N, X, Y) = readints()
    (i, comp) = completed_shells(N)
    rest = N - comp
    myshell = (abs(X)+abs(Y))/2
    print comp, myshell, i, rest
    if myshell < i:
        writeln("Case #%d: 1" % (case))
    elif (X==0) and (Y==0):
        writeln("Case #%d: 1" % (case))
    elif myshell > i+1:
        writeln("Case #%d: 0" % (case))
    elif X == 0:
        writeln("Case #%d: 0" % (case))
    elif Y+(2*i+1) <= rest:
        writeln("Case #%d: 1" % (case))
    else:
        writeln("Case #%d: %.16f" % (case, akh(rest, 1+Y)))
        

  

