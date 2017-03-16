f = open('A-large.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s[:-1]
    
    ans = ""
    
    L = len(s)

    currLast = "A"    
    for i in range(L):
        if s[i] >= currLast:
            ans = s[i] + ans
            currLast = s[i]
        else: 
            ans = ans + s[i]
                     
    outline = "Case #%d: " % (t) + ans + "\n" 
    o.write(outline)

o.close()
