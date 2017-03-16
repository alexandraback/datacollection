import sys
import math

# copy from http://ine.scripts.mit.edu/blog/2011/05/gaussian-elimination-in-python/
def myGauss(m):
    #eliminate columns
    for col in range(len(m[0])):
        for row in range(col+1, len(m)):
            r = [(rowValue * (-(m[row][col] / m[col][col]))) for rowValue in m[col]]
            m[row] = [sum(pair) for pair in zip(m[row], r)]
    #now backsolve by substitution
    ans = []
    m.reverse() #makes it easier to backsolve
    for sol in range(len(m)):
            if sol == 0:
                ans.append(m[sol][-1] / m[sol][-2])
            else:
                inner = 0
                #substitute in all known coefficients
                for x in range(sol):
                    inner += (ans[x]*m[sol][-2-x])
                #the equation is now reduced to ax + b = c form
                #solve with (c - b) / a
                ans.append((m[sol][-1]-inner)/m[sol][-sol-2])
    ans.reverse()
    return ans

"""
print myGauss([[2.0,1.0,-1.0,8.0],
               [-3.0,-1.0,2.0,-11.0],
               [-2.0,1.0,2.0,-3.0]])
"""

T = int(sys.stdin.readline())

for case in range(1, T + 1) :
    output = "Case #" + str(case) + ": "
    line = sys.stdin.readline().strip().split(" ")
    N = int(line[0])
    s = [ float (e) for e in line[1:]]

    martix = [ [1.0] * (N + 1) ]
    sum_s = sum(s)

    for _ in range(len(s)-1):
        row = [0.0] * (N + 1)
        row[_] = sum_s
        row[_ + 1] = -sum_s
        row[-1] = s[_ + 1] - s[_]

        martix.append(row)

    resVec = myGauss(martix)

    _sum = sum([e for e in resVec if e >= 0])
    for _ in range(len(resVec)):
        if resVec[_] >= 0:
            resVec[_] /= _sum
        else: 
            resVec[_] = 0


    result = " ".join(["{0:.6f}".format(e*100) for e in resVec])

    print output + result
