import sys
import math

file = sys.stdin
def getInt():
    return (file.readline())
def getInts():
    vals = list()
    for s in file.readline().split():
        vals.append(s)
    return vals

cases = int(getInt())
for i in range(cases):
    numbers = getInts()
    k = int(numbers[0])
    c = int(numbers[1])
    s = int(numbers[2])
    if s < k:
        print("Case #" + str(i + 1) + ": IMPOSSIBLE")
    else:
        #x = math.log(c, k)
        result = "Case #" + str(i + 1) + ": "
        result += ' '.join(str(test) for test in range(1, s + 1) )
        print(result)
