import time
import math
stime = time.time()

input = open("a.in" , "r")
output = open("a.out" , "w")
T = int(input.readline())

v = ["a", "e", "i", "o", "u"]

def getsubs(s, t):
    subs = []
    for i in range(t, len(s) + 1):
        for j in range(0, len(s) - i + 1):
            subs.append(s[j:j+i])
    return subs

def isuncommon(s, t):
    c = 0
    for i in range(0, len(s)):
        if not s[i] in v:
            c = c + 1
            if c >= t:
                return True
        else:
            c = 0
    return False
        

for j in range(1, T + 1):

    n = 0
    
    [s, t] = [x for x in input.readline().split(" ")]
    t = int(t)
    
    subs = getsubs(s, t)

    for i in range(0, len(subs)):
        if isuncommon(subs[i], t):
            n = n + 1
   
    print "Case #" + str(j) + ": " + str(n)
    output.write("Case #" + str(j) + ": " + str(n) + "\n")

input.close()
output.close()

print time.time() - stime, "seconds."
