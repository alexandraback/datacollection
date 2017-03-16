import os
import math

out = open('ans.txt', 'w')
fin = open('input.txt', 'r')
instr = fin.readlines()
fin.close()
t = int(instr[0])
for i in range(0, t):
    row = instr[i + 1]
    cnt = int(0)
    r = float(0.0)
    p = float(0.0)
    for s in row.split():
        if(cnt == 0):
            r = float(s)
            cnt = 1
        else:
            p = float(s)
            cnt = 2
    delta = (2 * r - 1) * (2 * r - 1) + 8 * p
    ans = (-(2 * r - 1) + math.sqrt(delta)) / 4
    integerans = int(ans)
    out.write('Case #' + str(i + 1) + ': ' + str(integerans) + '\n')

out.close()
