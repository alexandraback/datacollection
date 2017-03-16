#! /bin/python
#  LeLouch16 CodeJam '13 Qualification Round

import sys

if len(sys.argv) < 3:
    print "Not enough arguments"
    print "Usage '%s input.in output.out'" % sys.argv[0]
    sys.exit()

inpf  = sys.argv[1]
outf  = sys.argv[2]

fin   = open(inpf)
fout  = open(outf,'w')

debug = False

T = int(fin.readline().strip())
if debug: print "Number of test Cases:",T


############

def check(a):
    mr  = [ max(r) for r in a]
    mc  = [ max([a[i][j] for i in range(N)]) for j in range(M)]
    for i in range(N):
        for j in range(M):
            if (a[i][j] != mr[i]) and (a[i][j] != mc[j]):
                return False
    return True

for i in range(T):
    N,M = [int(c) for c in fin.readline().strip().split()]
    a   = [ [int(c) for c in fin.readline().strip().split()] for j in range(N) ]
    cancut = check(a)
    r   = 'YES' if cancut else 'NO'
    s = 'Case #'+str(i+1)+': '+r
    fout.write(s+'\n')
    if debug: print s

fin.close()
fout.close()


