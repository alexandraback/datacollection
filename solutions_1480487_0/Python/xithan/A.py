#!/usr/local/Cellar/python3/3.2.2/bin/python3

from GCJ import GCJ



def solve(infile):
    l = GCJ.readlist(int, infile)
    l.reverse()
    n = l.pop()
    l.reverse()
    res = [0] * n
    x = 0
    v = 0
    lwi = []
    j = 0
    for (i,a) in enumerate(l):
        lwi.append([a,i])
        x += a
    lwi.sort()
    wasserhoehe = float(lwi[0][0])
    breite = 0
    restwasser = x
    for i,(a,j) in enumerate(lwi):
        breite += 1
        if i < len(lwi)-1:
            b = lwi[i+1][0]
            v = (b-a)*breite
            #print("b-a %d" % (b-a))
            if restwasser - v  > 0:
                wasserhoehe = b
                restwasser =  restwasser - v
            elif restwasser - v == 0:
                wasserhoehe = b
                restwasser = restwasser - v
                break
            else:
                hoehe = restwasser / breite
                restwasser = 0
                wasserhoehe += hoehe
                break
        else:
            hoehe = restwasser / breite
            wasserhoehe += hoehe
        #print("i %d,a %d,  breite %d, v %d, restwasser %d, wasserhoehe %d" % (i,a,breite, v, restwasser, wasserhoehe))
       
    print(repr(lwi))     
    for (a,i) in lwi:
        r = float((wasserhoehe - a)/x*100)
        if r < 0:
            res[i] = "0"
        else:
            res[i] = "%.7f" % r
    return  " ".join(res) 

if __name__ == "__main__":
    GCJ("A",solve, path="/Users/phi/Dropbox/CodeJam/Current",).run()

    