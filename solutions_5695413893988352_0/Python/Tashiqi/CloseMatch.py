def calc(C,J,i,te,tc,tj):
    #te
    if C[i]=='?':
        if J[i]=='?':
            e1=("0"+te[i+1][0],"0"+te[i+1][1])
            e2=("1"+tc[i+1][0],"0"+tc[i+1][1])
            e3=("0"+tj[i+1][0],"1"+tj[i+1][1])
            e=min((e1,e2,e3),key=lambda x:(abs(int(x[1])-int(x[0])),x[0],x[1]))
            te[i]=e
        else:
            e1=(J[i]+te[i+1][0],J[i]+te[i+1][1])
            e2=(str(min(9,(int(J[i])+1)))+tc[i+1][0],J[i]+tc[i+1][1])
            e3=(str(max(0,(int(J[i])-1)))+tj[i+1][0],J[i]+tj[i+1][1])
            e=min((e1,e2,e3),key=lambda x:(abs(int(x[1])-int(x[0])),x[0],x[1]))
            te[i]=e
    else:
        if J[i]=='?':
            e1=(C[i]+te[i+1][0],C[i]+te[i+1][1])
            e2=(C[i]+tc[i+1][0],str(max(0,(int(C[i])-1)))+tc[i+1][1])
            e3=(C[i]+tj[i+1][0],str(min(9,(int(C[i])+1)))+tj[i+1][1])
            e=min((e1,e2,e3),key=lambda x:(abs(int(x[1])-int(x[0])),x[0],x[1]))
            te[i]=e
        else:
            if C[i]==J[i]:
                te[i]=(C[i]+te[i+1][0],J[i]+te[i+1][1])
            elif C[i]<J[i]:
                te[i]=(C[i]+tj[i+1][0],J[i]+tj[i+1][1])
            else:
                te[i]=(C[i]+tc[i+1][0],J[i]+tc[i+1][1])
    #tc
    if C[i]=='?':
        if J[i]=='?':
            tc[i]=("0"+tc[i+1][0],"9"+tc[i+1][1])
        else:
            tc[i]=("0"+tc[i+1][0],J[i]+tc[i+1][1])
    else:
        if J[i]=='?':
            tc[i]=(C[i]+tc[i+1][0],"9"+tc[i+1][1])
        else:
            tc[i]=(C[i]+tc[i+1][0],J[i]+tc[i+1][1])
    #tj
    if C[i]=='?':
        if J[i]=='?':
            tj[i]=("9"+tj[i+1][0],"0"+tj[i+1][1])
        else:
            tj[i]=("9"+tj[i+1][0],J[i]+tj[i+1][1])
    else:
        if J[i]=='?':
            tj[i]=(C[i]+tj[i+1][0],"0"+tj[i+1][1])
        else:
            tj[i]=(C[i]+tj[i+1][0],J[i]+tj[i+1][1])
T = int(input())
for t in range(T):
    C,J=input().split()
    te=[("0","0") for i in range(len(C)+1)]
    tc=[("0","0") for i in range(len(C)+1)]
    tj=[("0","0") for i in range(len(C)+1)]
    for i in range(len(C)-1,-1,-1):
        calc(C,J,i,te,tc,tj)
    print("Case #" + str(t+1) + ":",min((te[0],tc[0],tj[0]),key=lambda x:(abs(int(x[1])-int(x[0])),x[0],x[1]))[0][:-1],min((te[0],tc[0],tj[0]),key=lambda x:(abs(int(x[1])-int(x[0])),x[0],x[1]))[1][:-1])
