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

    
    min=2.0+b
        
    pr=1.0
    for i in range(a):
        pr*=c[i]

    p=2.0*b-a+2-pr*(b+1)
    if p<min:
        min=p

    for nb in range(1,a):
        p=p+2+(b+1)*pr
        pr=pr/c[a-nb]
        p=p-(b+1)*pr
        if p<min:
            min=p
    
    r=str(round(min,6))
    l=len(r.split(".")[1])
    r+="0"*(6-l)
    
    return r


def main():
    infile =  "A-large.in"
    outfile = "out.txt"
    solve(infile, outfile)

if __name__ == "__main__":
    main()

