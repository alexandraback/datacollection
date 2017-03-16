inf = open("inf.txt", "r")
ouf = open("ouf.txt", "w")

for i in range(int(inf.readline())):
    r, c, w = map(int, inf.readline().split())
    
    preres = (c // w) * r
    
    if w == 1:
        ouf.write("Case #" + str(i + 1) + ": " + str(r * c) + "\n")
    elif not c % w:
        ouf.write("Case #" + str(i + 1) + ": " + str(preres + w - 1) + "\n")
    else:
        ouf.write("Case #" + str(i + 1) + ": " + str(preres + w) + "\n")
    

inf.close()
ouf.close()