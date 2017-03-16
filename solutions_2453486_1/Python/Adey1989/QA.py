import sys

f = open(sys.argv[1])
T = int(f.readline())

def checkline(x):
    if x.count('O') == 0 and x.count('.') == 0:
        return 'X won'
    if x.count('X') == 0 and x.count('.') == 0:
        return 'O won'
    else:
        return 0

def checksquare(x):
    for ii in range(4):
        if checkline(M[4*ii:4*ii+4]) != 0:
            return checkline(M[4*ii:4*ii+4])
        if checkline(M[ii::4]) != 0:
            return checkline(M[ii::4])
    if checkline(M[0::5])!=0:
        return checkline(M[0::5])
    if checkline(M[3:15:3])!=0:
        return checkline(M[3:15:3])
    if x.count('.') != 0:
        return 'Game has not completed'
    else:
        return 'Draw'


for test in range(T):
    M = []
    for ii in range(4):
        M = M + list(f.readline().rstrip())

    f.readline()
    print "Case #%d: " % (test+1) + checksquare(M)

