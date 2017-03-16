#!/usr/bin/python
def ntest(name, n, start, stop):
    count = 0
    result = False
    for i in range(start,stop+1):
        if name[i] not in "aeiou":
            count+=1
            if count == n:
                result = True
                break
        else:
            count=0
    return result
import sys

if len(sys.argv) != 2:
    print "Usage: ./pta <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)

data = fin.readlines()
ntests = int(data[0].strip())
for i in range(1,ntests+1):
    info = data[i].strip().split()
    name = info[0]
    n = int(info[1])
    ncnt = 0
    for j in range(len(name)):
        for k in range(j+n-1, len(name)):
            if ntest(name, n, j, k):
                ncnt+=1
    print "Case #%d: %d"%(i,ncnt)
sys.exit(0)
