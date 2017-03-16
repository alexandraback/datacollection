f = open("A-large.in", 'r')
s = open("salida.txt", 'w')
cases = int(f.readline())
for case in xrange(cases):
    N = int(f.readline())
    if N == 0:
        s.write("Case #"+str(case+1)+": INSOMNIA\n")
    else:
        k = N
        digitosTomados = {}
        tomados = 0
        while tomados != 10:
            setN = set(str(N))
            for n in setN:
                if n not in digitosTomados:
                    digitosTomados[n] = True
                    tomados += 1
            N += k
        s.write("Case #"+str(case+1) + ": "+str(N-k)+"\n")
s.close()
f.close()