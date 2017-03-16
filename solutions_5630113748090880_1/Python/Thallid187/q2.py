f = open('B-large.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s[:-1]
    s = s.split()
    N = map(int, s)
    N = N[0]
    
    
    counts = [0 for x in range(2500+1)]    
    
    for i in range(2*N-1):
        s = f.readline()
        s = s[:-1]
        s = s.split()
        n = map(int, s)
        
        for j in range(N):
            counts[n[j]] += 1
            
    ans = ""

    for i in range(1, 2500+1):
        if counts[i] % 2 != 0: 
            ans += str(i)
            ans += " "
    
    ans = ans[:-1]
                     
    outline = "Case #%d: " % (t) + ans + "\n" 
    o.write(outline)

o.close()
