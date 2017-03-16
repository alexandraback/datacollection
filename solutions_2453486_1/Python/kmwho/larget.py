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


#####################
def update(a,i,j):
    a[i]   += 1
    a[4+j] += 1
    if i == j:
        a[8] += 1
    if i == 3-j:
        a[9] += 1

def check(M):
    full = True
    x = [0]*10
    o = [0]*10
    for i in range(4):
        for j in range(4):
            if M[i][j] == 'X':
                update(x,i,j)
            elif M[i][j] == 'O':
                update(o,i,j)
            elif M[i][j] == 'T':
                update(x,i,j)
                update(o,i,j)
            else:
                full = False
    if 4 in x:
        return 'X won'
    elif 4 in o:
        return 'O won'
    elif full:
        return 'Draw'
    return 'Game has not completed'


#####################


for i in range(T):
    M = [ [c for c in fin.readline().strip()] for j in range(4)]
    r = check(M)
    s = 'Case #'+str(i+1)+': '+r
    fout.write(s+'\n')
    if debug: print s
    fin.readline()



fin.close()
fout.close()

