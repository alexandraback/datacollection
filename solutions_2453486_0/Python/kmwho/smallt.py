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

T = int(fin.readline().strip())
print "Number of test Cases:",T

draw = True

############

def count(a):
    x  = a.count('X')
    o  = a.count('O')
    t  = a.count('T')
    if (x+t == 4):
        return 'X won'
    elif (o+t == 4):
        return 'O won'
    return ''

def check(M):
    for j in range(4):
        r = count(M[j])
        if r:
            return r
    for j in range(4):
        r = count([M[i][j] for i in range(4)])
        if r:
            return r
    r = count([M[i][i] for i in range(4)])
    if r:
        return r
    r = count([M[i][3-i] for i in range(4)])
    if r:
        return r
    for i in range(4):
        for j in range(4):
            if M[i][j] == '.':
                return 'Game has not completed'
    return 'Draw'


for i in range(T):
    M = [ [c for c in fin.readline().strip()] for j in range(4)]
    r = check(M)
    s = 'Case #'+str(i+1)+': '+r
    fout.write(s+'\n')
    print s
    fin.readline()

fin.close()
fout.close()


