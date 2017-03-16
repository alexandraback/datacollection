T = int(input())
vysledok = 0

for i in range(1, T+1):
    N = int(input())
    if (N == 0):
        vysledok = 'INSOMNIA'
    else:
        d = {}
        j = 0
        while (len(d) < 10):
            j += 1
            c = str(j*N)
            for x in range(0, len(c)):
                d[c[x]] = 1
            vysledok = c

    print("Case #"+str(i) + ": " + str(vysledok))
