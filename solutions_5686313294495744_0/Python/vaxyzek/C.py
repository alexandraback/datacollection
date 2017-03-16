import gcj


ifile, ofile = gcj.get_files('C')
T = int(ifile.readline().strip())

for t in range(T):
    N = int(ifile.readline().strip())
    F, S = [], []
    for i in range(N):
        first, second = ifile.readline().strip().split(' ')
        F.append(first)
        S.append(second)


    mfake = 0    
    for x in range(1 << N):
        Ff, Sf = [], []
        Fr, Sr = [], []

        for i in range(N):
            if (x >> i) & 1:
                Fr.append(F[i])
                Sr.append(S[i])
            else:
                Ff.append(F[i])
                Sf.append(S[i])
    
        #print(Ff, Sf, ':', Fr, Sr)

        Nr = len(Fr)
        Nf = len(Ff)
        
        fake = 0
        for i in range(Nf):
            ffake = Ff[i] in Fr
            sfake = Sf[i] in Sr
            #print(ffake, sfake)
            if ffake and sfake:
                fake += 1

        mfake = max(fake, mfake)


    gcj.print_answer(ofile, t, mfake)