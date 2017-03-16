from fractions import gcd
from math import log2
from math import ceil
from math import floor

fin = open('A-small-attempt0.in.txt','r')
#fin = open('A-large-practice.in.txt', 'r')
#fin = open('input.txt')

fout = open('output.txt', 'w')

numCases = int(fin.readline())

for cases in range(numCases):
    a, b = [int(x) for x in fin.readline().split('/')]

    g = gcd(a, b)
    a = a/g
    b = b/g
    lb = log2(b)

    if (ceil(lb)==lb):
        fout.write("Case #" + str(cases+1) + ": "+str(round(lb-floor(log2(a))))+'\n')
        #print(round(lb-floor(log2(a))))
    else:
        fout.write("Case #" + str(cases+1) + ": impossible"+'\n')
        #print("impossible")

    #fout.write("Case #" + str(cases+1) + ": "+'\n')

fin.close()
fout.close()