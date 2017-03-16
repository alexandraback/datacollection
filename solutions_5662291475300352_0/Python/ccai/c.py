#change these
inputfile = "C-small-1-attempt0.in"
outputfile = "C-small-1-attempt0.out"
#

prein = open(inputfile, 'r')
T = int(prein.readline())
maxes = []
for t in range(T):
    maxv = 0;
    minv = 1000000000;
    num = 0;
    N = int(prein.readline())
    for i in range(N):
        inp = prein.readline().split()
        H = int(inp[1])
        M = int(inp[2])
        num += H;
        if (M+H-1) > maxv:
            maxv = M+H-1
        if M < minv:
            minv = M
    maxes.append(min(360*minv*(num+1), 2*maxv*360)) #good limits
    
fin = open(inputfile, 'r')
fout = open(outputfile, 'w')

DEG = 360

T = int(fin.readline())
for t in range(T):
    MAX = maxes[t]
    
    fout.write("Case #" + str(t+1) + ": ")
    
    N = int(fin.readline())
    enc = 0
    minus = []
    plus = []
    
    for i in range(N):
        inp = fin.readline().split()
        D = int(inp[0])
        H = int(inp[1])
        M = int(inp[2])
        for j in range(H):
            speed = M+j
            val = (360-D)*speed
            minus.append(val)
            val += 360*speed
            while val < MAX:
                plus.append(val)
                val += 360*speed
            enc += 1
    
    minus.append(MAX)
    plus.append(MAX)
    minus.sort()
    plus.sort()
    min = enc
    m = 0
    p = 0
    while (m < len(minus) and p < len(plus)):
        if minus[m] < plus[p]:
            enc -= 1
            m += 1
            if enc < min:
                min = enc
        else:
            enc += 1
            p += 1
    
    fout.write(str(min) + "\n")
fout.close()