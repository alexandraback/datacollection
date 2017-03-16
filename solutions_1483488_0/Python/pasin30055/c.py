import sys

MAX_VAL = 20001
L = []

def precomp():
    for i in range(MAX_VAL):
        if i % 30000 == 0:
            print i
        s = set([])
        ist = str(i)
        for j in range(len(ist)):
            k = int(ist[j:] + ist[:j])
            if k > i and not k in s:
                s.add(k)
        L.append(s)

def findAns(a, b):
    res = 0
    for i in range(a + 1, b):
        for j in L[i]:
            if j < b:
                res += 1
    return res

precomp()

fin = open('C-small-attempt1.in', 'r')
fout = open('C.out', 'w')

t = int(fin.readline().strip())

for tests in range(t):
    print 'XXX'
    (a, b) = map(int, fin.readline().strip().split())
    fout.write('Case #' + str(tests+1) + ': ')
    fout.write(str(findAns(a - 1, b + 1)) + '\n')

fin.close()
fout.close()
