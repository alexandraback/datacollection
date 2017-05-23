fin= open('Ain')
fout= open('Aout', 'w')
N=int(fin.readline())

#fstring= fin.read()
fsout=''


for i in range(N):
    flout=fin.readline()
    flout2=fin.readline()
    probs=[float(z) for z in flout2.split()]
    
    fsout='Case #'+ str(i+1) +": "
    typed= int((flout.split())[0])
    total= int((flout.split())[1])
    
    expected=[total+2]
    for k in range(typed):
        ps=1
        for l in range(typed-k):
            ps=probs[l]*ps
        pf=1-ps

        expected.append(ps*(total-typed+2*k+1)+pf*((total-typed+2*k+1)+total + 1))
    print(expected)
    fsout= fsout+format(min(expected), '.6f') + "\n"
        

    fout.write(fsout)

fin.close()
fout.close()
    

