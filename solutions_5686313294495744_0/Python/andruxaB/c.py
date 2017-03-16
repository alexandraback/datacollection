filename = "C:\Users\Andri_000\Downloads\python\codejam\Round 1B\C\C-small-attempt1"

fin = open(filename+".in")
fout = open(filename+".out","w")

trials = int(fin.readline())

for T in xrange(trials):
    
    N = int(fin.readline())
    topics = []
    for i in range(N):
        topics.append(fin.readline().strip())
    
    numfaked = None
    for i in range(2**N):
        tru, fak = [], []
        for j in range(N):
            if (i%2**(j+1))/2**j==1:
                tru.append(topics[j])
            else:
                fak.append(topics[j])
        #print tru, fak
        for el1 in tru:
            for el2 in tru:
                if el1!=el2:
                    newel = el1.split()[0]+' '+el2.split()[1]
                    try:
                        fak.remove(newel)
                    except:
                        pass
                    if fak == []:
                        break
        if fak == []:
            numfaked = max(N - len(tru),numfaked)
            #print numfaked
    
    #print numfaked
    
    fout.write("Case #{0}: {1}\n".format(T+1, numfaked))
                    
fin.close()
fout.close()