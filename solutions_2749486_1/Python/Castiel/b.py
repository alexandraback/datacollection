import time
import math
stime = time.time()

input = open("b.in" , "r")
output = open("b.out" , "w")
T = int(input.readline())

def track(s):
    x = 0
    y = 0
    for i in range(0, len(s)):
        if s[i] == "N":
            y = y + i + 1
        if s[i] == "S":
            y = y - i - 1
        if s[i] == "E":
            x = x + i + 1
        if s[i] == "W":
            x = x - i - 1
    return [x, y]

for z in range(1, T + 1):

    [a, b] = [int(x) for x in input.readline().split(" ")]
    [x, y, c, d, j] = [abs(a), abs(b), 0, 0, 0]
    #print x, y, c, d, j
    ans = ""

    n = int((-1 + math.sqrt(1 + 8*abs(x)))/2)
    j = j + n
    for i in range(0, n):
        ans = ans + "E"
    c = (n*(n+1))/2

    m = int((-(2*n + 1) + math.sqrt((2*n + 1)**2 + 8*abs(y)))/2)
    j = j + m
    for i in range(0, m):
        ans = ans + "N"
    d = n*m + (m*(m+1))/2
    
    diag = int(math.sqrt((min(x-c, y-d))/2))

    while diag != 0:
        for i in range(0, diag):
            ans = ans + "W"
        for i in range(0, diag):
            ans = ans + "S"
        for i in range(0, diag):
            ans = ans + "E"
        for i in range(0, diag):
            ans = ans + "N"
        c = c + 2*(diag**2)
        d = d + 2*(diag**2)
        diag = int(math.sqrt((min(x-c, y-d))/2))

    while c != x:
        move = int(math.sqrt((x-c)))
        for i in range(0, move):
            ans = ans + "W"
        for i in range(0, move):
            ans = ans + "E"
        c = c + move**2

    while d != y:
        move = int(math.sqrt((y-d)))
        for i in range(0, move):
            ans = ans + "S"
        for i in range(0, move):
            ans = ans + "N"
        d = d + move**2

    if a < 0:
        for i in range(0, len(ans)):
            if ans[i] == "E":
                ans = ans[:i] + "W" + ans[i + 1:]
            elif ans[i] == "W":
                ans = ans[:i] + "E" + ans[i + 1:]
        
    if b < 0:
        for i in range(0, len(ans)):
            if ans[i] == "S":
                ans = ans[:i] + "N" + ans[i + 1:]
            elif ans[i] == "N":
                ans = ans[:i] + "S" + ans[i + 1:]
    
    if [a, b] != track(ans):
        print z, ans, [a, b], track(ans)
    
    print "Case #" + str(z) + ": " + ans
    output.write("Case #" + str(z) + ": " + ans + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
