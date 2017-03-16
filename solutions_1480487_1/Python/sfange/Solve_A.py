#python version 2.7
def solveProblem(fileName):
    
    fileIn=file(fileName)
    fileOut=file(fileName[:-2]+'out', 'w')
    
    T=int(fileIn.readline())
    
    for caseNum in xrange(1,T+1):
        D=[int(i) for i in fileIn.readline().strip('\n').split(' ')]
        N = D[0]
        S = D[1:]
        answer=solveCase(N,S)
        print answer
        fileOut.writelines("Case #%d: %s\n" % (caseNum, answer))
    print 'done'
    fileIn.close()
    fileOut.close()

def solveCase(N,S):
    X=sum(S)
    Y=X
    S3=S[:]
    while True:
        average=(X+Y)/float(N)
        S2=[i for i in S3 if i > average]
        if len(S2)>0:
            N=N-len(S2)
            Y=Y-sum(S2)
            S3=[i for i in S3 if i<=average]
        else:
            break
    P=[]
    diff  = [average-i for i in S]
    for d in diff:
        if d<0:
            d=0
        p='%.6f'%(d/X*100,)
        P.append(p)
    ret=' '.join(P)
    return ret
    

if __name__ == '__main__':
    fileName= r'C:\Users\i035514\Desktop\Codejam\R1B\A-large.in'
    solveProblem(fileName)