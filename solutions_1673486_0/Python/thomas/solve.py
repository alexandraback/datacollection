import math
#from mpmath import mp

def solve(infile, outfile):
    print "Input file: " + infile
    print "Output file: " + outfile
    inf = open(infile,'r')
    outf = open(outfile, 'w')
    N = int(inf.readline())
    for i in range(1, N + 1):
        print 'Case #' + str(i) + ' of ' + str(N) + ':',
        
        sol = solution(inf.readline()[:-1],inf.readline()[:-1])
        
#        nol=inf.readline()
#        lines=[]
#        for j in range(int(nol)):
#            lines.append(inf.readline()[:-1])
#        sol=solution(lines)
        
        print sol
        outf.write('Case #' + str(i) + ': ' + sol + '\n')
    inf.close()
    outf.close()

def solution(l1,l2):
    a=int(l1.split(" ")[0])
    b=int(l1.split(" ")[1])
    c=l2.split(" ")
    
    for i in range(len(c)):
        c[i]=float(c[i])
    
    scenario=[]
    
    scenario.append(2+b)
    
    for nb in range(a):
        pr=1.0
        for i in range(a-nb):
            pr*=c[i]
        scenario.append(pr*(b-a+1+2*nb)+(1-pr)*(2*nb+2*b-a+2))
    scenario.sort()
    r=str(round(scenario[0],6))
    l=len(r.split(".")[1])
    r+="0"*(6-l)
    
    return r


def main():
    infile =  "A-small-attempt0.in"
    outfile = "out.txt"
    solve(infile, outfile)

if __name__ == "__main__":
    main()

