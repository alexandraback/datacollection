# -*- coding: utf-8 -*-
"""
Created on Thu Apr  7 19:21:59 2016

@author: Benben
"""





def sol(IF):
    temp=IF.readline().split()
    B=int(temp[0])
    M=int(temp[1])
    res=''
    if M>2**(B-2):
        return 'IMPOSSIBLE'
    else:
        bb=bin(M-1)[2:]
        res='POSSIBLE\n'
        res+='0'*(B-1-len(bb))+bb+'1'+'\n'
        
        for i in range(2,B+1):
            res+='0'*(i)+'1'*(B-i)+'\n'
        return res[:-1]
          



IF=open('B-small-attempt0.in','r')
OF=open('B-small-output','w')
CaseN=int(IF.readline())
for i in range(1, CaseN+1):
    pretext='Case #{}: '.format(i)
    ans=sol(IF)
    if i<CaseN:
        ans=ans+'\n'
    OF.write(pretext+ans)
    
    
    
IF.close()
OF.close()


            
            