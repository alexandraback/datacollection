with open("A-small2016Q.in") as f:
    a = f.readline()
    for x in range (0, int(a)):
        y = f.readline()
        z = y
        b = int(z)
        if b == 0:
            print("Case #"+str(x+1)+": "+"INSOMNIA")
            continue
        else:
            pass
        c = 0
        total = 0
        alist = [0,0,0,0,0,0,0,0,0,0]
        while total<10:
            total = 0
            c = c+1
            d = c*b
            e = str(d)
            for j in range (0, len(e)):
                g = e[j]
                h = int(g)
                alist[h] = 1
            for i in range (0,10):
                total = total + alist[i]
        print("Case #"+str(x+1)+": "+ str(d))

            
