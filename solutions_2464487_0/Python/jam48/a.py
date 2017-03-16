f = open("DATA1.txt")
g = open("OUT1.txt",'w')
n = f.readline().strip()
for x in range(int(n)):
    a = int(0)
    i = f.readline().strip().split(" ")
    b = int(0)
    cont = True
    while cont:
        y = 2 * (int(i[0])+ (2*a)) +1 
        if (y+b) <= int(i[1]):
            a = a + 1
            b = b + y
        else:
            cont = False   
    g.write("Case #"+str(int(x+1))+": "+str(a)+"\n")
g.close()
