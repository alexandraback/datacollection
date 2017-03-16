def Ord(i):
    return ord(i)-65

def solve(IF):
    s=IF.readline().split()[0]
    save=[0]*26
    for i in s:
        save[Ord(i)]+=1
    numD=[0]*10
    numD[0]=save[Ord('Z')]
    numD[2]=save[Ord('W')]
    numD[4]=save[Ord('U')]
    numD[5]=save[Ord('F')]-numD[4]
    numD[6]=save[Ord('X')]
    numD[7]=save[Ord('S')]-numD[6]
    numD[8]=save[Ord('G')]
    numD[1]=save[Ord('O')]-numD[0]-numD[2]-numD[4]
    numD[3]=save[Ord('R')]-numD[0]-numD[4]
    numD[9]=save[Ord('I')]-numD[5]-numD[6]-numD[8]
    res=''
    for n in range(10):
        if numD[n]>0:
            res+=str(n)*numD[n]
    return res
    
    
    
    
    
    
    
    
    
    
    
    
IF=open('A-small-attempt0.in','r')
OF=open('A-output','w')
temp=IF.readline()
CaseN=int(temp)


for i in range(1, CaseN+1):
    pretext='Case #{}: '.format(i)
    ans=solve(IF)
    if i<CaseN:
        ans=ans+'\n'
    OF.write(pretext+ans)
    
    
    
IF.close()
OF.close()
