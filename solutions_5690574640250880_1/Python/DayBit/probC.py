'''
Created on 12/04/2014

@author: david
'''

def mat(rs,cs):
    res = [['*']*cs for _ in range(rs)]
    res[0][0] = 'c'
    return res
    
fIn=open("C-large.in")

T=int(fIn.readline())
P=[]
for i in range(T):
    r, c, m  = [int(x) for x in fIn.readline().strip().split()]
    P.append((r,c,m))
  
case = 0
fRes = open("res.txt", "w")  
for r,c,m in P:
    h = r*c-m
    #print(r,c,m)
    case += 1
    dmin = min(r, c)
    dmax = max(r, c)    
    print("Case #{}:".format(case)) 
    fRes.write("Case #{}:\n".format(case))  
    mm = mat(r,c)
    if h==1:
        pass
    elif dmin==1:
        if dmin==r:
            for i in range(1,h): mm[0][i]='.'
        else:
            for i in range(1,h): mm[i][0]='.'
    elif (h==2 or h==3 or h==5 or h==7) and dmin>1:
        print("Impossible")
        fRes.write("Impossible\n") 
        continue
    elif h%2==1 and dmin==2:
        print("Impossible")
        fRes.write("Impossible\n") 
        continue
    else:
        nr = h//c
        resto = h%c
        if nr>=3:
            #print("---->3",h,r,resto)
            for rr in range(nr):
                for cc in range(c):
                   mm[rr][cc]='.' 
            if resto==1:
                mm[nr-1][c-1]='*'
                resto+=1
            for cc in range(resto):
                mm[nr][cc]='.'      
        elif nr==2:
            #print("->2")
            for rr in range(nr):
                for cc in range(c):
                   mm[rr][cc]='.' 
            if resto==1:
                mm[nr-1][c-1]='*'
                mm[nr-2][c-1]='*'
                resto+=2
            for cc in range(resto):
                mm[nr][cc]='.' 
        else:
            if h==9:
                #print("-----------------------> A else",h)
                for rr in range(3):
                    for cc in range(3):
                        mm[rr][cc]='.' 
            elif h%2==0:
                #print("-----------------------> B else",h)
                for rr in range(2):
                    for cc in range(h//2):
                        mm[rr][cc]='.' 
            else:
                #print("-----------------------> C else",r,c,m,h)
                for rr in range(2):
                    for cc in range((h-3)//2):
                        mm[rr][cc]='.'
                for cc in range(3):
                   mm[2][cc]='.'
        mm[0][0]='c'
 
    for lin in mm:
        print(''.join(lin))
        fRes.write(''.join(lin)+"\n")  
    
fRes.close()