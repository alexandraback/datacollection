import sys

def puedoFormar(di):
    se = set()
    for k, v in di.iteritems():
        if len(se) == 0: se = set(v)
        else:
            for nn in list(se):
                for nu in v:
                    se.add(nn + nu)
                    se.add(nu)
    return se
            
def main(lines):
    c, d, v = map(lambda x : int(x), lines[0].split())
    vals = map(lambda x : int(x), lines[1].split())
    se = set()
    ma = {}
    for i in vals:
        ll = []
        for j in xrange(1, c + 1):
            ll.append(j * i)
        ma[i] = ll
    puedo = puedoFormar(ma)
    ad=0
    for i in xrange(1,v+1):
        if not i in puedo:
            ad+=1
            for nu in list(puedo):
                for j in xrange(c):
                    puedo.add(nu+(j+1)*i)
                    puedo.add((j+1)*i)
    return ad
    
if __name__ == "__main__":
   filename = sys.argv[1]
   with open(filename, "r") as f:
       f.readline()
       i = 0
       lines = []
       for l in f.readlines():
           i += 1
           lines.append(l.strip())
           if i % 2 == 0:
               print "Case #" + str(i / 2) + ": " + str(main(lines))
               lines = [] 
