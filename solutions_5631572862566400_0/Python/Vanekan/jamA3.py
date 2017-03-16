def chain(k,s):
    global b
    global n
    m = s
    for i in range(0,n):
        if b[i] == k[-1] and i not in k and i != b[k[0]]:
            k.append(i)
            m = max(m,chain(k,s+1))
            k.pop()
    return m

rtt = input()

for tc in range(1, rtt+1):
    b = []
    cycles = []
    
    a = 2
    
    n = input()
    r = raw_input().split()
    
    for i in range(0,n):
        cycles.append([])
        b.append(int(r[i])-1)
    
    maxc = []
    for i in range(0,n):
        maxc.append(chain([i],0))
    
    
    for i in range(0,n):
        next = b[i]
        cycles[i].append(i)
        while (i != next):
            cycles[i].append(next)
            next = b[next]
            if len(cycles[i]) > n:
                next = i
                cycles[i]=[]

    dc = []    
    for i in range(0,n):
        if cycles[i] != []:
            add = True
            for j in range(0,len(dc)): 
                if set(cycles[i]) == set(dc[j]):
                    add = False
            if add:
                dc.append(cycles[i])
    
    flat = [item for sublist in dc for item in sublist]
    pot = []
    for i in range(0,n):
        if i not in flat:
            pot.append(i)

    twocycles = []

    for i in range(0,len(dc)):
        a = max(len(dc[i]),a)
        if (len(dc[i]) == 2):
            twocycles = twocycles+dc[i]
    
    aa = len(twocycles)
    for i in range(0,len(twocycles)):
        aa = aa + maxc[twocycles[i]]
    a = max(a,aa)
    
            
    
    
    print "Case #%d: %d" % (tc,a)