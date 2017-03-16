import numpy
import sys

bases = [2,3,5]

def read(name):
    f = open(name)
    l = f.readlines()
    l.reverse()
    r = {}
    f.close()
    r['t'] = int(l.pop())
    for i in range(r['t']):
        c = {}
        c['i'] = i+1
        c['r'],c['n'],c['m'],c['k'] = map(int, l.pop().split())
        c['f'] = []
        for j in range(c['r']):
            c['f'].append(list(map(int, l.pop().split())))
        r[i] = c
    return r

def base(n, b):
    a = 0
    while n % b == 0:
        a += 1
        n = n // b
    return a

def solve(c):
    print("Case #1:")
    for l in c['f']:
        subsolve(l, c['k'], c['n'])

def subsolve(f, k, n):
    fa = []
    for i in range(len(f)):
        fa.append([])
        for b in bases:
            fa[i].append(base(f[i], b))
    fa = numpy.array(fa)
    mx = [max(fa[:,i]) for i in range(len(bases))]
    mn = [min(fa[:,i]) for i in range(len(bases))]
    
    four = 0
    while sum(mx) > n:
        if mx[0] < 2:
            print("error")
            break
        else:
            mx[0] -= 2
            four += 1

    two = mx[0] + n-sum(mx)-four
    print("%s%s%s%s" % (two*'2', mx[1]*'3', four*'4', mx[2]*'5'))

def main():
    c = read(sys.argv[1])
    for i in range(c['t']):
        solve(c[i])

if __name__ == "__main__":
    main()
