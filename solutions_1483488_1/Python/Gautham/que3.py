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
    A = int(sp[0])
    B = int(sp[1])
    score = 0
    for i in range(A,B):
        s = set([])
        wr = str(i)
        for j in range(1,len(wr)):
            p = int(wr[j:]+wr[:j])
            if (p > i) and (p <= B) and (p not in s):
                s.add(p)
                score += 1
    ofile.write('Case #'+str(count)+': '+str(score)+'\n')
    count += 1
ofile.close()
