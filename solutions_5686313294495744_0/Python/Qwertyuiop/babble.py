from itertools import chain, combinations

def powerset(iterable):
  xs = list(iterable)
  # note we return an iterator rather than a list
  return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )

def valid(first, second):
    upFirst = set([i[0] for i in first])
    upSecond = set([i[1] for i in first])
    for (a,b) in second:
        if a not in upFirst: return False
        if b not in upSecond: return False
    return True

## pairs of strings
def solve(N):
    m=0
    for first in powerset(N):
        second=N[::]
        for i in first:
            second.remove(i)
        if valid(first, second):
            m=max(m, len(second))
    if m==len(N):
        print "WTF"
    return m


import sys
f = open(sys.argv[1], "r")
F = open(sys.argv[1]+".out", "w")

for caseNum in range(int(f.readline().rstrip())):
    print caseNum
    pairs=[]
    for i in range(int(f.readline().rstrip())):
        p=f.readline().rstrip().split(" ")
        p=(p[0],p[1])
        pairs.append(p)
    F.write("Case #%d: %d\n" % (caseNum+1, solve(pairs)))
F.close()