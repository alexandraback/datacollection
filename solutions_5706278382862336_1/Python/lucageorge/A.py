f = open("A-large.in", "r")
out = open("Output.txt", "w")

def functie(xxx, generatie):
    while xxx != 1:
        xxx *= 2
        generatie += 1
        if xxx > 1:
            #xxx -= 1
            xxy = xxx -  1
            generatiey = functie(xxy, generatie+1)
            if generatiey > generatie:
                break
    return generatie

T = int(f.readline())
for caz in range(1, T+1):
    generatie = 0
    P, Q = (int(e) for e in f.readline()[:-1].split('/'))
    xxx = P/float(Q)
    generatieXX = functie(xxx, generatie)
    
    while xxx != 1:
        xxx *= 2
        generatie += 1
        if xxx > 1:
            xxx -= 1
        if generatie > 40:
            generatie = 'impossible'
            break
    if generatie != 'impossible':
        generatie = generatieXX
        
    out.write("Case #" + str(caz) +": " + str(generatie) + "\n")
    #print(generatie)
out.close()
