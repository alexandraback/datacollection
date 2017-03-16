def table(m):
    t = [2*m] * (m + 1)
    t[1] = 1
    for i in xrange(1, m):
        t[i+1] = min(t[i+1], 1 + t[i])
        t[flip(i)] = min(t[flip(i)], 1 + t[i])
    return t

def solve(n):
    pass

def flip(n):
    a = list(str(n))
    a.reverse()
    return int(''.join(a))


f = open('a.in', 'r')
lines = f.readlines()

cases = [int(line) for line in lines[1:]]
print(len(cases))
print(cases)

tab = table(1000000)

g = open('a.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(tab[cases[i]]) + '\n')
g.close()
