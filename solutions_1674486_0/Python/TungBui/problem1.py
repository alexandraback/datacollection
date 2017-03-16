inputFile='input.txt'
outputFile='output1.txt'
inputFile1='A-small-attempt1.in'
inputFile2='A-large.in'



def readInput(f):
    fr=open(inputFile1,'r')
    t=int(fr.readline())
    for caseNumber in range(0,t):
        n=int(fr.readline())
        tmp=[0]*(n+1)
        path=[]
        for i in range(0,n+1):
            path.append(tmp[:])
        for i in range(1,n+1):
            s=fr.readline().split()
            for j in range(1,len(s)):
                path[i][int(s[j])]=1
        process(caseNumber+1,f,path,n)
    fr.close()

def process(caseNumber,f,path,n):
    found=False
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i!=j:
                count=bfs(i,j,path,n)
                if count>1:
                    found=True
                    break 
    writeOutput(caseNumber,f,found)

def bfs(start,finish,path,n):
    front,rear=0,0
    queue=[start]
    count=0
    while front<=rear:
        u=queue[front]
        front+=1
        for v in range(1,n+1):
            if path[u][v]==1 :
                rear+=1
                queue.append(v)
                if v==finish:
                    count+=1
                if count==2:
                    break
    return count

    
    
def writeOutput(caseNumber,f,found):
    f.write('Case #{0:d}: '.format(caseNumber))
    if found:
        f.write('Yes\n')
    else:
        f.write('No\n')
    

def main():
    f=open(outputFile,'w')
    readInput(f)
    f.close()

if __name__=='__main__':
    main()
