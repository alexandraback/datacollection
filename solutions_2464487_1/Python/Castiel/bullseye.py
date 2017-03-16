import time
import math
stime = time.time()

input = open("bullseye.in" , "r")
output = open("bullseye.out" , "w")
T = int(input.readline())

for j in range(1, T + 1):

    [r, t] = [float(x) for x in input.readline().split(" ")]

    s = (2*r + 1)
    ans = (2 - s + math.sqrt(((s-2)*(s-2) + 8*t)))/4
    ans = int(math.floor(ans))

    t2 = ans*s + ans*(ans - 1)*2

    while t < t2:
        t3 = (ans - 1) * 4 + s
        t2 = t2 - t3
        ans = ans - 1
    
    print "Case #" + str(j) + ": " + str(ans)
    output.write("Case #" + str(j) + ": " + str(ans) + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
