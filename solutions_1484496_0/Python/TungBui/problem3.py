inputFile='input.txt'
outputFile='output3.txt'
inputFile1='C-small-attempt1.in'
inputFile2=''

def readInput():
    f=open(inputFile1,'r')
    t=int(f.readline())
    L=bin(20)
    for i in range(0,t):
        s=f.readline().split()
        n=int(s[0])
        num=[]
        for j in range(1,len(s)):
            num.append(int(s[j]))
        process(n,num,i+1,L)
    f.close()

def process(n,num,caseNumber,L):
    s=[]
    for i in range(0,len(L)):
        kq=0
        for j in range(0,len(L[i])):
            if L[i][j]==1:
                kq+=num[j]
        s.append(kq)
    found=False
    for i in range(0,len(s)):
        if not found:
            for j in range(0,len(s)):
                if not found:
                    if s[i]==s[j] and L[i]!=L[j]: 
                        found=True
                        pos1=i
                        pos2=j
    writeOutput(num,L,pos1,pos2,found,caseNumber)
    
def writeOutput(num,L,pos1,pos2,found,caseNumber):
    f=open(outputFile,'a')
    f.write('Case #{0:d}:\n'.format(caseNumber))
    if found:
        for i in range(0,len(L[pos1])):
            if (L[pos1][i])==1:
                f.write(str(num[i]))
                f.write(' ')
        f.write('\n')
        for i in range(0,len(L[pos2])):
            if L[pos2][i]==1:
                f.write(str(num[i]))
                f.write(' ')
        f.write('\n')
    else:
        f.write('Impossible\n')
    f.close()
    
def bin(n):
    L=[]
    s=[0]*n
    f=[1]*n
    while s!=f:
        i=len(s)-1
        while i>=0 and s[i]==1:
            i-=1
        s[i]=1
        s[i+1:]=[0]*len(s[i+1:])
        L.append(s[:])
    L.append(f[:])
    return L

def main():
    f=open(outputFile,'w')
    f.close()
    readInput()
    
if __name__=='__main__':
    main()