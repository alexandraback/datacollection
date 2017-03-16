import sys

def inv(n):
    return int(str(n)[::-1])

def createPot10():
    l = [1, 10]
    for i in xrange(2, 15):
        voy = l[i - 1]
        estoy = 10 ** (i - 1)
        rep9 = (10 ** ((i) / 2) - 1)
        voy += rep9
        estoy += rep9
#         print estoy
        estoy = inv(estoy)
#         print estoy 
        voy += 1
        voy += (10 ** i - estoy)
        l.append(voy)
    return l

POT_10 = createPot10()

def llego(a, b):
    if b%10==0:
        return llego(a, b-1)
    le = len(str(a))
#     print str(b)[-le / 2:], str(b)[:le / 2]
    voy = int(str(b)[:le / 2][::-1])
    estoy = 10 ** (le - 1) + voy
    if estoy != inv(estoy):
        estoy = inv(estoy)
        voy += 1
#     print estoy, voy
    voy += b - estoy
    return voy

def main(l):
    n = int(l)
    cif = len(l)
    voy = POT_10[cif - 1]
    toy = 10 ** (cif-1)
    if n<=20: return n
    if n == toy:
        return voy
    if n%10==0:
        n=n-1
        voy=voy+1
    m = min(llego(toy, n), llego(toy, int(str(n)[::-1]))+1)
    return m + voy

if __name__ == "__main__":
   filename = sys.argv[1]
   with open(filename, "r") as f:
       f.readline()
       i = 0
       for l in f.readlines():
           i += 1
           ret = main(l.strip())
#            print "CON L  ", l
           print "Case #" + str(i) + ": " + str(ret) 
