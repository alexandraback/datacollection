import math
inp = open("input.txt", "r")
outp = open("output.txt", "w")

n = int(inp.readline().strip())

for i in xrange(n):         
    s = inp.readline().strip().split()
    r, t = map(int, s)
    
    #print(t)
    L, R = 0, r + t
    while(R - L > 1):
        m = (R + L) / 2
        #print(m, ((2 * (r * 2 + 1) + (m - (r + 2) / 2 + 1) * 2) * (m - (r + 2) / 2 + 1)) / 2, t)
        if(((2 * (r * 2 + 1) + 4 * m - 4) * m) / 2 <= t):
            L = m
        else:
            R = m
    outp.write("Case #" + str(i + 1) + ": " + str(L) + "\n")

outp.close()
inp.close()
