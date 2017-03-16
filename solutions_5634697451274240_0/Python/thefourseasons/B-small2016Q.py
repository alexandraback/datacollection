with open("B-small2016Q.in") as z:
    a = z.readline()
    for b in range (0,int(a)):
        c = z.readline()
        differs = 0
        for d in range (0,len(c)-2):
            if c[d]!=c[d+1]:
                differs = differs + 1
            else:
                differs = differs
        if c[-2] == "-":
            differs = differs + 1
        else:
            pass
        print("Case #"+str(b+1)+": "+ str(differs))
