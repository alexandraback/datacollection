
def brat(R, C, W):
    if W==1:
        return C*R
    if C==W:
        return C + (R-1)
    
    #shoot out all Rows
    score = (R-1)*(C/W)
    
    #to get first hit
    score += C/W
    #can move ship
    if C%W > 0:
        score += 1
    #sink
    score += W - 1
    
    return score



if __name__ == "__main__":        
    fin = open('input.txt','r')
    fout = open('output.txt','w')
    
    T = int(fin.readline())
    
    for i in range(T):
        temp = fin.readline().split(' ')
        ans = brat(int(temp[0]),int(temp[1]),int(temp[2]))
        fout.write("Case #%d: %d\n"%(i+1, ans))
    
    fin.close()
    fout.close()
    print 'done'