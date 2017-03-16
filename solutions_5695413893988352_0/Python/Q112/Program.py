import sys
import os
from math import *

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

if __name__ == '__main__':
    T = int(In.readline())
    for x in range(T):
        print(x)
        c,j = In.readline().rstrip('\n').split(' ')
        L = len(c)
        
        cq, jq = [], []
        for i in range(L):
            if c[i] == '?':
                cq.append(i)
            if j[i] == '?':
                jq.append(i)
        cq = set(cq)
        jq = set(jq)
        
        if cq.intersection(jq) == {}:
            for pos in cq:
                c[pos] = j[pos]
            for pos in jq:
                j[pos] = c[pos]
            out = c+ ' ' +j
        else:
            if len(cq) == L:
                    out = L*'0' + ' ' + L*'0'
            corig = 0
            jorig = 0
            for i in range(L):
                if not i in cq:
                    corig += int(c[i])*10**(L-i-1)
                if not i in jq:
                    jorig += int(j[i])*10**(L-i-1)
            print([jorig,corig,cq,jq])
            min = abs(corig - jorig)
            strc = str(corig)
            strc = (L-len(str(strc)))*'0' + strc
            strj = str(jorig)
            strj = (L-len(str(strj)))*'0' + strj
            games = [strc+ ' ' + strj]
            for a in range(10**len(cq)):
                ctmp = corig
                stra = str(a)
                stra = (len(cq)-len(stra))*'0'+stra
                count = 0
                for i in cq:
                    ctmp += int(stra[count])*10**(L-i-1)
                    count+=1
                count = 0   
                for b in range(10**len(jq)):
                    jtmp = jorig
                    strb = str(b)
                    strb = (len(jq)-len(strb))*'0'+strb
                    for i in jq:
                        jtmp += int(strb[count])*10**(L-i-1)
                        count+=1
                    count=0
                    if abs(ctmp - jtmp) == min:
                        strc = str(ctmp)
                        strc = (L-len(str(strc)))*'0' + strc 
                        strj = str(jtmp)
                        strj = (L-len(str(strj)))*'0' + strj                       
                        games.append(strc+ ' ' + strj)
                    if abs(ctmp - jtmp) < min:
                        strc = str(ctmp)
                        strc = (L-len(str(strc)))*'0' + strc 
                        strj = str(jtmp)
                        strj = (L-len(str(strj)))*'0' + strj                     
                        min = abs(ctmp - jtmp)
                        games = [strc+ ' ' + strj]
                   
                out = games[0]
                    
              
                    
                    
                
        Out.write('Case #{}: {}\n'.format(x+1,out))

 
                

                    
                  
            
