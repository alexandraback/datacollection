import sys

T = int(input())
for N in range(1, T + 1):
    out = 'Case #' + str(N) + ':'
    n = int(input())
    liste = []
    for _ in range(2 * n - 1):
        liste.append([int(i) for i in input().split()])
    nb = {}
    for l in liste:
        for x in l:
            if x in nb:
                nb[x] += 1
            else:
                nb[x] = 1
    l = []
    for x in nb:
        if nb[x] % 2 == 1:
            l.append(x)
    l.sort()
    for x in l:
        out += ' ' + str(x)
    out += '\n'
    sys.stdout.write(out)
    sys.stdout.flush()
    sys.stderr.write(out)
    sys.stderr.flush()