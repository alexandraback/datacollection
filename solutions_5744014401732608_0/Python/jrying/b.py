import sys
import fileinput
import re

#fileio
# fileName = 'B-large'
fileName = 'B-small-attempt2'
# fileName = 'B-test'
input = fileName + ".in"
output = fileName + ".out"

###
with open(input) as fi, open(output, "w") as fo:
    count = 0
    for line in fi.readlines()[1:]:
        print line
        result = 0
        B, M = map(int, line.strip().split(" "))
        print B, M

        ###
        result = ""
        if M > 2**(B-2):
            result = "IMPOSSIBLE"
        else:
            result = "POSSIBLE"
            arr = [[0 for _ in xrange(B)] for _ in xrange(B)]
            min_needed = 27
            if M == 2**(B-2):
                for i in range(1, B):
                    arr[0][i] = 1
                min_needed = 1
            else:
                for i in range(B):
                    if M>>i & 1:
                        arr[0][B-i-2] = 1
                        min_needed = min(min_needed, B-i-2)
            for i in range(max(1, min_needed), B):
                for j in range(i+1, B):
                    arr[i][j] = 1
            # print "\n".join(map(lambda x: " ".join(map(str, x)), arr))
            result += "\n"+"\n".join(map(lambda x: "".join(map(str, x)), arr))

        ###
        #normal
        count += 1
        resultStr = "Case #"+str(count)+": "+str(result)
        print resultStr
        fo.write(resultStr+'\n')
