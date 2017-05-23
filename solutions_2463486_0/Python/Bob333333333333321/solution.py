memo = {}
def genFairAndSquares(maxDigs, start="", midIncluded = False):
    res = set()
    if 2 * len(start) - int(midIncluded) <= maxDigs:
        if midIncluded:
            whole = start[::-1] + start[1:]
        else:
            whole = start[::-1] + start
        if whole in memo:
            return memo[whole]
##        print(whole)
##        if len(whole) % 2 == 0:
##            print(whole)
        wholeAsInt = int(whole) if whole else 0
        wholeSqrd = wholeAsInt ** 2
        wholeSqrdAsStr = str(wholeSqrd)
        if wholeSqrdAsStr == wholeSqrdAsStr[::-1]:
            res.add(wholeSqrdAsStr)
    else:
        return []
##    if midIncluded:
##        b = start[1:]
##    else:
##        b = start
##    if len(start) > 1:
##        a = b[::-1]
##        L = len(b)
##        a = int(a)
##        b = int(b)
##        if str(a ** 2)[0] != str(b ** 2)[-1] or str(a ** 2)[:L] > str(b ** 2)[-L:]:
##            return res
        
        
    for i in range(10) if start else range(1, 10):
##        print(res)
        res = res.union(res, genFairAndSquares(maxDigs, str(i) + start, False))
        res = res.union(res, genFairAndSquares(maxDigs, str(i) + start, True))
    memo[whole] = res
    return res

def genFairAndSquaresBT(maxDigs):
    res = []
    for i in range(1, 10 ** (maxDigs + 1)):
        if str(i) == str(i)[::-1]:
            k = i ** 2
            if str(k) == str(k)[::-1]:
                res.append(k)
    return res

##k = genFairAndSquares(8)
##k = list(k)
##k = list(int(i) for i in k)
##k.sort()
##print(k)
from math import *
nums = [0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004]

def getFromFile(path = r'C:\Python32\google code jam 2013\qualification round\c_small.txt'):
    reader = open(path)
    data = reader.readlines()
    reader.close
    for i in range(len(data)):
        if data[i][-1] == "\n":
            data[i] = data[i][:-1]
    data.reverse()
    numCases = int(data.pop())
    output = ""
    for j in range(numCases):
        lims = data.pop().split()
        lims = list(int(i) for i in lims)
        curRes = 0
        for i in nums:
            if lims[0] <= i <= lims[1]:
                curRes += 1
        output += "Case #" + str(j + 1) + ": " + str(curRes) + "\n"
    output = output[:-1]
    print(output)
getFromFile()
