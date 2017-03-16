T = int(raw_input())

for t in range(T):
    C, D, V = map(int, raw_input().split(" "))
    bag = [0] * (V+1)
    nominals = map(int, raw_input().split(" "))
    bag[0] = 1
    wynik = 0

    for nom in nominals:
        for i in range(V, -1, -1):
            if (nom + i <= V) and (bag[i] == 1):
                bag[nom+i] = 1
         
    for i in range(1, V+1):
        if (bag[i] == 0):
            wynik += 1
            for j in range(V, -1, -1):
                if (i+j <= V) and bag[j] == 1:
                    bag[i+j] = 1

    print "Case #" + str(t+1) + ": " + str(wynik)
 
