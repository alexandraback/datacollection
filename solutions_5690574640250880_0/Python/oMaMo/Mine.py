'''
Created on Apr 12, 2014

@author: ononon1
'''
fname = "../Mine4.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    [R,C,M] = map(int,f.readline().split())
    #print(R,C,M)
    b = R*C-M
    if(R==1):
        ans = ""
        for k in range(C):
            if(k==0):
                ans = "c"
            elif(k<b):
                ans= ans+"."
            else:
                ans= ans+"*"
        ans = ans+"\n"
    elif(C==1):
        ans = ""
        for j in range(R):
            if(j == 0 ):
                ans = "c"
            elif(j<b):
                ans= ans+"."
            else:
                ans= ans+"*"
            ans = ans+"\n"
    elif(R==2):
        if(b==1 or (b%2==0 and b>2)):
            for j in range(R):
                for k in range(C):
                    if(j == 0 and k==0):
                        ans = "c"
                    elif(k<b/2):
                        ans= ans+"."
                    else:
                        ans= ans+"*"
                ans = ans+"\n"
        else:
            ans = "Impossible\n"
    elif(C==2):
        if(b==1 or (b%2==0 and b>2)):
            for j in range(R):
                for k in range(C):
                    if(j == 0 and k==0):
                        ans = "c"
                    elif(j<b/2):
                        ans= ans+"."
                    else:
                        ans= ans+"*"
                ans = ans+"\n"
        else:
            ans = "Impossible\n"
    else:
        if(b==2 or b==3 or b==5 or b==7):
            ans = "Impossible\n"
        else:
            if(b > C*2):
                r = b/C
                rn = b%C
                flag1 = 0
                flag2=0
                #print(r,rn)
                if(rn==1 and r >2):
                    r = r-1
                    flag1 = 1
                    rn = rn+1
                elif(rn==1 and r==2):
                    r = 0
                    flag2 = 1
                    rn = rn+2
                #print(r,rn)
                for j in range(R):
                    for k in range(C):
                        if(j == 0 and k==0):
                            ans = "c"
                        elif(j<r):
                            ans= ans+"."
                        elif(j==r and flag1==0 and flag2==0 and k <rn):
                            ans= ans+"."
                        elif(j==r and flag1==1):
                            if(k==C-1):
                                ans= ans+"*"
                            else:
                                ans= ans+"."
                        elif(j==r+1 and flag1==1 and k <rn):
                            ans= ans+"."
                        elif(j<2 and flag2==1):
                            if(k==C-1):
                                ans= ans+"*"
                            else:
                                ans= ans+"."
                        elif(j==2 and flag2==1 and k <rn):
                            ans= ans+"."
                        else:
                            ans= ans+"*"
                    ans = ans+"\n"
            else:
                c = b/2
                cn = b%2
                if(cn==1 and c>0):
                    c=c-1
                    cn=3
                #print(c,cn)
                for j in range(R):
                    for k in range(C):
                        if(j == 0 and k==0):
                            ans = "c"
                        elif(k<c and j <2):
                            ans= ans+"."
                        elif(j==2 and k <cn and c>0):
                            ans= ans+"."
                        else:
                            ans= ans+"*"
                    ans = ans+"\n"
    #fout.write(str(R) + " " + str(C) + " " +str(M))
    fout.write("Case #"+str(i)+":\n"+ ans)
