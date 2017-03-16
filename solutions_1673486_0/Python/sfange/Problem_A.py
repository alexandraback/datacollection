def solution(fileName):
    fileIn=file(fileName)
    fileOut=file(fileName[:-2]+'out', 'w')
    T=int(fileIn.readline())
    for caseNum in xrange(1,T+1):
        
        line = fileIn.readline().rsplit(' ')
        A=int(line[0])
        B=int(line[1])
        line = fileIn.readline().rsplit(' ')
        P=[]
        for i in xrange(A):
            P.append(float(line[i]))
        
        result=solve(A,B,P)
        
        answer = "Case #%d: %6f\n" % (caseNum, result)
        print answer,
        fileOut.writelines(answer)
    fileIn.close()
    fileOut.close()

def solve(A,B,P):
    result=0
    possible_stroks=[]
    for i in xrange(0,A+1):
        p_list=P[:i]
        p_correct=1
        
        for p in p_list:
            p_correct=p_correct*p
        p_wrong=1-p_correct
        s_correct=(A-i)+(B-i)+1
        s_wrong=s_correct+B+1
        possible_stroks.append(p_correct*s_correct+p_wrong*s_wrong)
    possible_stroks.append(1+B+1)
    possible_stroks.sort()
    result=possible_stroks[0]
    return result
    

if __name__ == '__main__':
    fileName= r'C:\Users\i035514\Desktop\Codejam\R1\A-small-attempt0.in'
    solution(fileName)