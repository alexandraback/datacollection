from math import ceil
inputf = open('D-large.in','r')
outputf = open('fractal-large-attempt.txt','w')
lines = inputf.readlines() 
t = int(lines[0])
u = 0
while t>0:
    t-=1
    u+=1
    k, c, s = tuple(map(int, lines[u].split()))
    if ceil(k/float(c))>s:
        outputf.write("Case #%d: " %u + "IMPOSSIBLE\n")
        continue
    elif k<=s:
        outputf.write("Case #%d: " %u +" ".join(map(str, range(1, k+1)))+"\n")
        continue
    if c==1:
        outputf.write("Case #%d: " %u +" ".join(map(str, range(1, k+1)))+"\n")
        continue
    s = [0 for i in range(0, k, c)]
    for i in range(len(s)):
        a = c*i+1
        f = a
        b = c
        while b>1:
            if f>=k:
                a *= k
                b-=1
                f+=1
                continue
            a = f+1+(a-1)*(k)
            f+=1
            b-=1
        s[i] = str(a)
    sol = ' '.join(s)
    outputf.write("Case #%d: " %(u) +sol+"\n")
    
inputf.close()
outputf.close()
