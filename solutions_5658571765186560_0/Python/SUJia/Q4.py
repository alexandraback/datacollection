import numpy as np

f = open('D-small-attempt1.in.txt', 'r')
fr = open('D-small-attempt1.out.txt', 'w')
#f = open('input', 'r')
#fr = open('output', 'w')
line = f.readline()
ntot = int(line.split()[0])
for i in range(ntot):
    line = f.readline()
    X, R, C = map(int, line.split()[:3])
    print X, R, C
    fill = True
    if X >= 7: fill = False
    else:
        if (R * C) % X != 0: fill = False
        maxlist = [1,2,3,4,5,6]
        minlist = [1,1,2,3,3,3]
        if max(R,C) < maxlist[X-1]: fill = False
        if min(R,C) < minlist[X-1]: fill = False    
    if fill == True:
        fr.write('Case #'+ str(i+1) + ': GABRIEL\n')
    else:
        fr.write('Case #'+ str(i+1) + ': RICHARD\n')
f.close()
fr.close()