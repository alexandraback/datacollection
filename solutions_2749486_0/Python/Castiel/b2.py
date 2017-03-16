
import time
import math
stime = time.time()

input = open("b.in" , "r")
output = open("b.out" , "w")
T = int(input.readline())

for z in range(1, T + 1):

    ans = ""
    a = 0
    b = 0
    j = 0
    [c, d] = [int(x) for x in input.readline().split(" ")]

    x = abs(c)
    y = abs(d)

    n = int((-1 + math.sqrt(1 + 8*abs(x)))/2)

    for i in range(0, n):
        ans = ans + "E"

    a = (n * (n + 1))/2
    j = j + n

    m = int((-(2*n + 1) + math.sqrt((2*n + 1)**2 + 8*abs(y)))/2)

    for i in range(0, m):
        ans = ans + "N"

    j = j + m

    b = n * m + (m * (m + 1))/2
    if y != b:
        for i in range(0, abs(y - b)):
            if y > b:
                ans = ans + "SN"
            else:
                ans = ans + "NS"
        b = y

    if x != a:
        for i in range(0, abs(x - a)):
            if x > a:
                ans = ans + "WE"
            else:
                ans = ans + "EW"
        a = x

    if c < 0:
        for i in range(0, len(ans)):
            if ans[i] == "E":
                ans = ans[:i] + "W" + ans[i + 1:]
            elif ans[i] == "W":
                ans = ans[:i] + "E" + ans[i + 1:]
        
    if d < 0:
        for i in range(0, len(ans)):
            if ans[i] == "S":
                ans = ans[:i] + "N" + ans[i + 1:]
            elif ans[i] == "N":
                ans = ans[:i] + "S" + ans[i + 1:]


    print "Case #" + str(z) + ": " + ans
    output.write("Case #" + str(z) + ": " + ans + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
