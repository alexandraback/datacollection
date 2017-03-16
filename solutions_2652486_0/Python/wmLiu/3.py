allpos = {}
for i in range(64):
    q1 = i % 4
    q2 = (i//4) % 4
    q3 = (i//16) % 4
    t = [q1 + 2,q2 + 2,q3 + 2]
    t.sort()
    x = tuple(t)
    if x in allpos:
        allpos[x] += 1
    else:
        allpos[x] = 1

def getpos(numbers, product):
    x, y, z = numbers
    return [1, x , y, z, x * y, y * z, x * z, x * y * z].count(product)

def solve(_p):
    best = -1
    for (k,i) in enumerate(allpos):
        j = 1
        for d in _p:
            j *= getpos(i, d)
        if j*allpos[i] > best:
            best = j * allpos[i]
            res = i
    return res

fin = open('C-small-1-attempt0.in', 'r') 
T = int(fin.readline().rstrip())
caseNo = 0
fout = open('C-small.out', 'w')
R, N, M, K = [int(x) for x in fin.readline().rstrip().split()]
fout.write('Case #1:\n')
for j in range(R):
    ps = [int(x) for x in fin.readline().rstrip().split()]
    fout.write(''.join(str(x) for x in solve(ps)) + '\n')

fin.close()
fout.close()

