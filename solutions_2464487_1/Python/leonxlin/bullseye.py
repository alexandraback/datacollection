
from decimal import *

fin = open('bullseye_in.txt')
fout = open('bullseye.out','w')
n_input = int(fin.readline())

getcontext().prec = 100

for i_input in range(n_input):
    temp = [ Decimal(a) for a in fin.readline().split() ]
    r = temp[0]
    t = temp[1]

    n = -(2*r-1) + Decimal((2*r-1)**2 + 8*t).sqrt()
    n /= 4

    #print n

    fout.write("Case #" + str(i_input+1) + ": " + str(int(n)) + "\n")
    



fin.close()
fout.close()
