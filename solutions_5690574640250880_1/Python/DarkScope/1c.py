import sys
import os
T=int(raw_input())
for t in range(T):
    n,m,B=raw_input().split(' ')
    n=int(n)
    m=int(m)
    B=int(B)
    print "Case #%d:"%(t+1)
    if m*n-B==1:
        for i in range(n):
            for j in range(m):
                if i==0 and j==0:
                    sys.stdout.write('c')
                else:
                    sys.stdout.write('*')
            sys.stdout.write("\n")
        continue
    map=[]
    for i in range(n):
        map.append([])
        for j in range(m):
            map[i].append(0)
    l_B=B
    l_n=n
    p_n=1
    l_m=m
    p_m=1
    def output():
        #print "l_n",l_n
        #print "l_m",l_m
        #print "p_m",p_m
        #print "o_n",p_n
        for i in range(n):
            for j in range(m):
                if map[i][j]==4:
                    sys.stdout.write("c")
                elif map[i][j]==1:
                    sys.stdout.write("*")
                else:
                    sys.stdout.write(".")
            sys.stdout.write("\n")
        #for i in range(n):
        #    for j in range(m):
        #        sys.stdout.write(str(map[i][j]))
        #    sys.stdout.write("\n")
        #sys.stdout.write("\n")
    def mines(x,y):
        ans=[]
        for i in range(-1,2):
            for j in range(-1,2):
                ans.append([x+i,y+j])
        re_ans=[]
        for s in ans:
            if s[0]>=0 and s[0]<n and s[1]>=0 and s[1]<m:
                re_ans.append(s)
        return re_ans
            
    def work():
        for i in range(n):
            for j in range(m):
                k=0
                if map[i][j]==1:
                    continue
                for s in mines(i,j):
                    if map[s[0]][s[1]]==1:
                        map[i][j]=2
                        break
        flag=True
        op=[]
        for i in range(n):
            if flag:
                for j in range(m):
                    if map[i][j]==0:
                        map[i][j]=4
                        op.append([i,j])
                        flag=False
                        break
            else:
                break
        l=0
        r=1
        if flag==False:
            while l<r:
                now=op[l]
                l=l+1
                extend=mines(now[0],now[1])
                for s in extend:
                    if map[s[0]][s[1]]==0:
                        r=r+1
                        op.append(s)
                        map[s[0]][s[1]]=3
            for i in range(n):
                for j in range(m):
                    if map[i][j]==2:
                        os=mines(i,j)
                        for s in os:
                            if map[s[0]][s[1]]==3 or map[s[0]][s[1]]==4:
                                map[i][j]=5
            for i in range(n):
                for j in range(m):
                    if map[i][j]==0 or map[i][j]==2:
                        return False
            return True
        else:
            return False
    while (l_B>0):
        if l_n>l_m:
            if l_B>=l_m:
                l_B=l_B-l_m
                for i in range(l_m):
                    map[n-p_n][i]=1
                p_n=p_n+1
                l_n=l_n-1
            elif l_B==l_m-1:
                for i in range(l_B-2,-1,-1):
                    map[n-p_n][l_m-i-1]=1
                map[n-p_n-1][l_m-1]=1
                
                l_B=0
            else:
                for i in range(l_B-1,-1,-1):
                    map[n-p_n][l_m-i-1]=1
                    
                l_B=0
        else:
            if l_B>=l_n:
                l_B=l_B-l_n
                for i in range(l_n):
                    map[i][m-p_m]=1
                p_m=p_m+1
                l_m=l_m-1
            elif l_B==l_n-1:
                for i in range(l_B-2,-1,-1):
                    map[l_n-i-1][m-p_m]=1
                map[l_n-1][m-p_m-1]=1
                l_B=0
            else:
                for i in range(l_B-1,-1,-1):
                    map[l_n-i-1][m-p_m]=1
                l_B=0
    
    if work():
        output()
        pass
    else:
        #print n,m,B
        #output()
        sys.stdout.write("Impossible\n")

    
