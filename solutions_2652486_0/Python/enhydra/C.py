import sys, random

inp = [[int(j) for j in i.split(' ')] for i in sys.stdin.read().strip().splitlines()]

R, N, M, K = inp[1]
sets = inp[2:]

print 'Case #1:'
for s in sets:
    res = []
    for n1 in range(2, M+1):
        for n2 in range(2, M+1):
            for n3 in range(2, M+1):
                prod = set()
                prod.add(n1*n2*n3)
                prod.add(n1*   n3)
                prod.add(n1*n2   )
                prod.add(n1      )
                prod.add(   n2*n3)
                prod.add(      n3)
                prod.add(   n2   )
                prod.add(1)
                if set(s) - prod == set():
                    res += ['%d%d%d' % (n1, n2, n3)]
    if res == []:
        res = ['111']
    print res[random.randrange(0, len(res))]


