infile = open("A.in", "r+")
outfile = open("output.txt",  "w+")

t = int(infile.readline())

def simplify(p,q):
    k = 0
    temp = q
    while(temp % 2 == 0):
        temp = temp/2
    while(p%2 != 1):
        p = p/2.0
        q = q/2.0
    if temp == 1: return p,q, (p<=q)
    else: return p/temp, q/temp, (p<=q and p%temp == 0)
            
for case in range(t):
    p,q = [int(i) for i in infile.readline().split("/")]
    p,q, valid = simplify(p,q)
    n = 0
    if (p == 1 and q == 1):
        n = 1        
    else:
	if valid:
            while(True):
                n += 1
                q = q/2
                if q <=  p: break
        else: n = -1
    if n == -1: outfile.write("Case #"+str(case+1)+": impossible"+"\n")
    else: outfile.write("Case #"+str(case+1)+": "+str(n)+"\n")




infile.close()
outfile.close()
