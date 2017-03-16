#!/usr/bin/python
def ntest(name, n, start):
    for i in range(start,start+n):
        if name[i] in "aeiou":
            return False
    return True

def getidx(name,n,length):
    idx = 0
    cnt = 0
    vals = [-1]
    while idx<length:
        if name[idx] not in "aeiou":
            cnt+=1
            if cnt >= n:
                vals.append(idx-n+1)
        else:
            cnt = 0
            if length-idx < n:
                break
        idx+=1
    return vals

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
    namelength = len(name)
    ncnt = 0
    indices = getidx(name,n,namelength)
    curridx = 1
    length = len(indices)
    while curridx < length:
        ncnt+= (namelength-n-indices[curridx]+1)*(indices[curridx]-indices[curridx-1])
        curridx+=1
        
    print "Case #%d: %d"%(i,ncnt)
sys.exit(0)
