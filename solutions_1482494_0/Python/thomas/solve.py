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
        
#        sol = solution(inf.readline()[:-1],inf.readline()[:-1])
        
        nol=inf.readline()
        lines=[]
        for j in range(int(nol)):
            lines.append(inf.readline()[:-1])
        sol=solution(lines)
        
        print sol
        outf.write('Case #' + str(i) + ': ' + sol + '\n')
    inf.close()
    outf.close()

def sum(a):
    s=0
    for i in a:
        s+=i
    return s


def solution(lines):
    stars=0
    times=0
    first=[]
    second=[]
    comp1=[]
    comp2=[]
    for i in lines:
        first.append(int(i.split(" ")[0]))
        second.append(int(i.split(" ")[1]))
        comp1.append(0)
        comp2.append(0)

    while (sum(comp2)<len(comp2) and stars>=0):
        print comp1,comp2,first,second,stars
        m=min(second)
        n=second.index(m)
        if comp2[n]+comp1[n]==0:
            if stars>=m:
                #stars-=m
                comp2[n]=1
                second[n]=2002
                times+=1
                stars+=2
                continue

        if comp2[n]==0 and comp1[n]==1:
            if stars>=m:
                #stars-=m
                comp2[n]=1
                second[n]=2002
                times+=1
                stars+=1
                continue


        m=min(first)
        n=first.index(m)
        if stars>=m and comp1[n]==0:
            #stars-=m
            first[n]=2002
            comp1[n]=1
            times+=1
            stars+=1
            continue
        
        if stars<m:
            break
    
#print comp1
#    print comp2
    
    if sum(comp2)<len(comp2):
        return "Too Bad"
    else:
        return str(times)

def main():
    infile =  "B-small-attempt1.in"
    #infile="b.txt"
    outfile = "out.txt"
    solve(infile, outfile)

if __name__ == "__main__":
    main()

