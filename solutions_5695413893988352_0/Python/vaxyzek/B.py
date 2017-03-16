import gcj, itertools

ifile, ofile = gcj.get_files('B')

T = int(ifile.readline().strip())
for t in range(T):
    C, J = ifile.readline().strip().split(' ')
    CJ = C + J
    missed = CJ.count('?')
    mn = pow(10, len(CJ))
    Cm = pow(10, len(CJ))
    ans = ''
    L = len(CJ)
    #print(mn, Cm)
    for m in itertools.product([0,1,2,3,4,5,6,7,8,9], repeat=missed):

        CJn = CJ
        mi = 0
        for i in range(len(CJn)):
            if CJn[i] == '?':
                CJn = CJn[:i] + str(m[mi]) + CJn[i+1:]
                mi += 1
        Cn = int(CJn[:L//2])
        Jn = int(CJn[L//2:])
        
        #print(CJn)

        if abs(Cn - Jn) < mn:
            mn = abs(Cn - Jn)
            Cm = Cn
            Jm = Jn
            ans = CJn
        if abs(Cn - Jn) == mn and Cn < Cm:
            mn = abs(Cn - Jn)
            Cm = Cn
            Jm = Jn
            ans = CJn

    gcj.print_answer(ofile, t, ans[:L//2] + ' ' + ans[L//2:])