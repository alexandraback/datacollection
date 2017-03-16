inputFile='input.txt'
inputFile1='A-large.in'
outputFile='output1.txt'

def readInput():
    f=open(inputFile1,'r')
    t=int(f.readline())
    for i in range(0,t):
        s=f.readline().split()
        n=int(s[0])
        j=[]
        for k in range(1,len(s)):
            j.append(int(s[k]))
        process(n,j,i+1)
    f.close()

def process(n,j,caseNumber):
    x=sum(j)
    avr=2*x/n
    result=[0]*n
    count=n
    tmpX=x
    for i in range(0,len(j)):
        if j[i]>=avr:
            result[i]=0
            count-=1
            tmpX-=j[i]
    nAvr=(tmpX+x)/count
    for i in range(0,len(j)):
        if j[i]<avr:
            kq=(nAvr-j[i])/x*100
            result[i]=kq
    writeOutput(caseNumber,result)    

def writeOutput(caseNumber,y):
    f=open(outputFile,'a')
    f.write('Case #{0:d}: '.format(caseNumber))
    for i in range(0,len(y)-1):
        f.write('{0:.6f} '.format(y[i]))
    f.write('{0:.6f}\n'.format(y[-1]))
    f.close()
    
def main():
    f=open(outputFile,'w')
    f.close()
    readInput()
    
if __name__=='__main__':
    main()