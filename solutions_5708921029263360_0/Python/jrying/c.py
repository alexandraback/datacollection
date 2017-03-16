import sys
import fileinput
import re
#fileio
# fileName = 'C-large'
fileName = 'C-small-attempt0'
# fileName = 'C-test'
input = fileName + ".in"
output = fileName + ".out"

###
with open(input) as fi, open(output, "w") as fo:

    count = 0
    for line in fi.readlines()[1:]:
        print line
        J, P, S, K = map(int, line.split())
        arr = [J, P, S]
        result = 0
        ###
        m1 = min(arr)
        m3 = max(arr)
        m2 = sum(arr) - m1 - m3
        pos = min(m1*m2*K, m1*m2*m3)
        result = []
        curent = []
        # Gen top k coms
        for i in xrange(pos):
            result.append([i%J+1, (i+1)%P+1, (i+2)%S+1])
        result = str(pos) + "\n"+"\n".join(map(lambda x: " ".join(map(str, x)), result))

        ###
        #normal
        count += 1
        resultStr = "Case #"+str(count)+": "+str(result)
        print resultStr
        fo.write(resultStr+'\n')
