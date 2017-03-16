from math import factorial


def bi(n,k):
    return factorial(n)/factorial(k)/factorial(n-k)

with open("b.in","r") as f:
    rows = f.readlines()[1:]
    for t,row in enumerate(rows):
        n,x,y = map(int,row.split(" "))
        #print n,x,y
        piani = 1
        tot = 1
        while tot < n:
            tot += 2*piani+3
            piani += 2
        if n != tot:
            piani -= 2
            tot -= 2*piani+3
        av = n - tot
        print n,tot
        #print "costruico piani: "+str(piani)
        #print "avvanzano "+str(av)
        if (y > piani or y > av):
            print "Case #"+str(t+1)+": 0.0"
        elif (abs(x)<=piani-y):
            print "Case #"+str(t+1)+": 1.0"
        elif (abs(x)>piani-y+1):
            print "Case #"+str(t+1)+": 0.0"
        else:
            p = 0
            for i in range(0,y+1):
                #print i, float(bi(av,i)) * (0.5)**av
                p+= float(bi(av,i)) * (0.5)**av
            print "Case #"+str(t+1)+": "+str(1-p)
