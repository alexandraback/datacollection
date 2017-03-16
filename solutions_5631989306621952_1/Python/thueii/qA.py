import sys

def g(x, c):
    if len(x) == 0:
        return c
    else:
        if c >= x[0]:
            return c + x
        else:
            return x + c        

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    x = ''
    for c in l:
        x = g(x, c)
    print("Case #%d: %s" % (i + 1, x))

