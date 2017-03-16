
fin = open('energy.in')
fout = open('energy.out','w')
n_input = int(fin.readline())

for i_input in range(n_input):
    temp = [ int(a) for a in fin.readline().split() ]
    E = temp[0]
    R = temp[1]
    N = temp[2]
    V = [ int(a) for a in fin.readline().split() ]

    if R > E:
        R = E

    #print i_input

    bests = [0]*(E+1)
    for v in V:
        nbests = [0]*(E+1)
        for e in range(R,E+1):
            nbests[e] = max ([bests[k]+(k-e+R)*v for k in range(e-R,E+1)])
        bests = nbests

    #print bests[R]
    fout.write("Case #" + str(i_input+1) + ": " + str(bests[R]) + "\n")
    



fin.close()
fout.close()
