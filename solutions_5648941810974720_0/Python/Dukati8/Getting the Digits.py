t=int(input())
for i in range (t):
    s=input()
    numbers=[]
    for j in range (10):
        numbers.append(0)
    s=''.join(sorted(s))
    numbers[0]=s.count("Z")
    numbers[2]=s.count("W")
    numbers[4]=s.count("U")
    numbers[6]=s.count("X")
    numbers[5]=s.count("F")-numbers[4]
    numbers[1]=s.count("O")-numbers[0]-numbers[2]-numbers[4]
    numbers[7]=s.count("S")-numbers[6]
    numbers[8]=s.count("G")
    numbers[9]=s.count("I")-numbers[5]-numbers[6]-numbers[8]
    numbers[3]=s.count("T")-numbers[2]-numbers[8]
    out=""
    for j in range (10):
        for k in range (numbers[j]):
            out+=str(j)
    print ("Case #" + str(i+1) + ": " + out)
