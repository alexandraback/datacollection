import sys

t = int(sys.stdin.readline())

def match(line, pattern):
    for i in xrange(len(line)):
        if pattern[i] != "?" and pattern[i] != line[i]:
            return False

    return True
        

def solve(a, b):
    pattern = "{{:0{}}}".format(len(a))
    mn = 10**77
    for i in xrange(10 ** len(a)):
        for u in xrange(10 ** len(a)):
            if abs(i - u) < mn:
                linea = pattern.format(i)
                lineb = pattern.format(u)

                if match(linea, a) and match(lineb, b):
                    mn = abs(i - u)
                    ba = linea
                    bb = lineb

    print "Case #{}: {} {}".format(e+1, ba, bb)
    sys.stdout.flush()

for e in xrange(t):
    a, b = sys.stdin.readline().split()
    solve(a, b)
