filename = "C:\Users\Andri_000\Downloads\python\codejam\Round 1B\B\B-small-attempt2"

fin = open(filename+".in")
fout = open(filename+".out","w")

trials = int(fin.readline())

def gen(i, sc, s, alln):
    if i==len(sc)-1:
        for el in sc[i]:
            alln.append(s+el)
    else:
        for el in sc[i]:
            gen(i+1, sc, s+el, alln)

for T in xrange(trials):
    
    [s1, s2] = fin.readline().split()
    
    N = len(s1)
    
    sc1, sc2 = [], []
    
    for i in range(N):
        if s1[i] == '?':
            sc1.append(map(str,range(10)))
        else:
            sc1.append([s1[i]])
        if s2[i] == '?':
            sc2.append(map(str,range(10)))
        else:
            sc2.append([s2[i]])
            
    all1, all2 = [], []
    gen(0, sc1, '', all1)
    gen(0, sc2, '', all2)
    
    df, s1, s2 = None, None, None
    for n1 in all1:
        for n2 in all2:
            diff = abs(int(n1)-int(n2))
            if df == None:
                df, s1, s2 = diff, n1, n2
            else:
                diff = abs(int(n1)-int(n2))
                if (diff < df) or (diff == df and int(n1)<int(s1)) or (diff == df and int(n1)==int(s1) and int(n2)<int(s2)):
                    df, s1, s2 = diff, n1, n2   
    
    #print s1, s2
    #print all1, all2
    fout.write("Case #{0}: {1} {2}\n".format(T+1, s1, s2))
                    
fin.close()
fout.close()