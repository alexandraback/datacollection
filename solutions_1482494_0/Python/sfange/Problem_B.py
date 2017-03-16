def solution(fileName):
    fileIn=file(fileName)
    fileOut=file(fileName[:-2]+'out', 'w')
    T=int(fileIn.readline())
    for caseNum in xrange(1,T+1):
        
        line = fileIn.readline()
        N=int(line)
        S=[]
        for i in xrange(N):
            line = fileIn.readline().rsplit(' ')
            S.append([int(line[0]),int(line[1])])
        
        result=solve(N,S)
        if result!='Too Bad':
            answer = "Case #%d: %d\n" % (caseNum, result)
        else:
            answer = "Case #%d: Too Bad\n" % caseNum
        print answer,
        fileOut.writelines(answer)
    fileIn.close()
    fileOut.close()

def solve(N,S):
    result=0
    S.sort(key=lambda x:x[1])
    cs=0
    cr=0
    for i in xrange(N):
        cr=S[i][1]
        if cs>=cr:
            if S[i][0]==-1:
                cs+=1
            else:
                cs+=2
            S[i][0]=-1
            result+=1
            
        else:
            #cs<cr
            j=N-1
            while j>=0:
                if cs>=S[j][0] and S[j][0]!=-1:
                    cs+=1
                    S[j][0]=-1
                    result+=1
                    if cs>=cr:
                        break
                    else:
                        j=N
                j=j-1       
                    
            if cs<cr:
                return 'Too Bad'
            
            if S[i][0]==-1:
                cs+=1
            else:
                cs+=2
            S[i][0]=-1
            result+=1
            
    return result
    

if __name__ == '__main__':
    fileName= r'C:\Users\i035514\Desktop\Codejam\R1\B-small-attempt2.in'
    solution(fileName)