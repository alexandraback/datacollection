'''
Created on Apr 11, 2015

@author: jozefmokry
'''
import os

def read(path):
    with open(path, 'r') as f:
        T = f.readline().strip()
        T = int(T)
        outPath = os.path.splitext(path)[0] + 'OUT.txt'
        out = open(outPath, 'w')
        for i in range(T):
            line = f.readline().strip()
            maxN, sNums = line.split(' ')
            maxN= int(maxN)
            sNums = list(sNums)
            sNums = map(int, sNums)
            assert(maxN == len(sNums) - 1), (maxN, len(sNums)-1)
            ans = solve(sNums)
            out.write('Case #%d: %d\n' % (i+1, ans))
        out.flush()
        out.close()
    print 'DONE'

def solve(sNums):
    standing = 0
    extra = 0
    for sLevel, nPeople in enumerate(sNums):
        if nPeople > 0:
            if standing >= sLevel:
                standing += nPeople
            else:
                need = sLevel - standing
                standing += need
                extra += need
                standing += nPeople
    return extra

read('A-large.in')