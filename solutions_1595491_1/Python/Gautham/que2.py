import fileinput
import string

ofile = open('out.txt','w')

count = 0
cases = 0
for line in fileinput.input():
    if count == 0:
        cases = int(line)
        count += 1
        continue
    sp = line.split()
    N = int(sp[0])
    S = int(sp[1])
    p = int(sp[2])
    score = 0
    for i in range(3,N+3):
        c = int(sp[i])
        c -= p
        if c < 0:
            continue
        c = (c/2)
        c = (p-c)
        if c <= 1:
            score += 1
            continue
        elif c == 2 and S != 0:
            S -= 1
            score += 1
            continue
    ofile.write("Case #"+str(count)+': '+str(score)+'\n')
    count += 1

ofile.close()
    
