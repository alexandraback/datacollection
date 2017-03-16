import itertools

def combis(number, lengths):
    return itertools.permutations(itertools.combinations(range(number, 0, -1), lengths), lengths)

def check2(comb, length, bffs):
    for i in range(length):
        person = comb[i]
        if (comb[(i+length+1)%length] != bffs[person]) and (comb[(i+length-1)%length] != bffs[person]):
            return False

    return True               

f = open('C-small-attempt1.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s[:-1]
    s = s.split()
    N = map(int, s)
    N = N[0]
    print N    
    
    s = f.readline()
    s = s.split()
    bffs = [0 for x in range(N+1)]
    tmp = map(int, s)    
    for i in range(N):
        bffs[i+1] = tmp[i]
    
    fin = False

    for i in range(N, 2, -1):
        if fin == True:
            break
        c = itertools.combinations(range(i, 0, -1), i)
        
        for x in c:
            c2 = itertools.permutations(x, i)            
            
            for y in c2:
                        
                fin = check2(y, i, bffs)
                if fin == True:
                    ans = i
                    break
    
    outline = "Case #%d: %d\n" % (t, ans)
    o.write(outline)

o.close()
