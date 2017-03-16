import numpy as np

f = open('A-large.in.txt', 'r')
fr = open('A-large.out.txt', 'w')
line = f.readline()
ntot = int(line.split()[0])
for i in range(ntot):
    line = f.readline()
    [Smax, Slist] = line.split()[:2]
    print Smax, Slist
    ires = 0
    isum = 0
    for j in range(int(Smax)):
        isum = isum + int(Slist[j])
        # at pos j+1, it needs shyness level j+1, 
        # but there are isum number of people already standing up
        if isum < (j+1): 
            ires = ires + (j+1-isum)
            isum = j+1        
    fr.write('Case #'+ str(i+1) + ': ' + str(ires) + '\n')
f.close()
fr.close()