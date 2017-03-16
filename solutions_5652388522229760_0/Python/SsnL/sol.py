f = open('A-small-attempt0.in', 'r')
o = open('A.out', 'w')

def find(n):
    s = set()
    c = n
    s.update(str(c))
    while len(s) < 10:
        c += n
        s.update(str(c))
    return c

m = int(f.readline().strip())
i = 1

while i <= m:
    n = int(next(f).strip())
    if n == 0:
        print('Case #{0}: INSOMNIA'.format(i), file = o)
    else:
        print('Case #{0}: {1}'.format(i, find(n)), file = o)
    i += 1

f.close()
