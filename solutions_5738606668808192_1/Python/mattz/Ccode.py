import sys

def flip(S):
    temp = S[::-1]
    out = ''
    for i in range(len(temp)):
        if temp[i] == '+':
            out += '-'
        else:
            out += '+'

    return out

infile = open(sys.argv[1],'r')

T = infile.readline()
T = T.rstrip()

for index in range(int(T)):
    print 'Case #' + str(index+1) + ':'
    NJ = infile.readline().rstrip().split(' ')
    N = int(NJ[0])
    J = int(NJ[1])

    count = 0

    for i in range(N-3):
        for j in range(i+2,N-3):
            for k in range(j+2,N-3):
                if count < J:
                    jamcoin = '1'
                    ones = [i, i+1, j, j+1, k, k+1]
                    for n in range(N-2):
                        if n in ones:
                            jamcoin += '1'
                        else:
                            jamcoin += '0'
                    jamcoin += '1'
                    count += 1
                    print jamcoin + ' 3 4 5 6 7 8 9 10 11'
