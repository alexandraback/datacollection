filename  = "B-small-attempt7.in"#"B-large.in"#
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for Ca in range(T):
    [C,J]=str.split(f.readline())
    #print([C,J])
    N=len(C)
    [mindif,Cbest,Jbest] =[0,'','']
    #[mindif,Cbest,Jbest] 
    for j in range(N-1,-1,-1):
        #print([mindif,Cbest,Jbest,j])
        Cmax =int('0'+C[j+1:].replace('?','9'))
        Cmin =int('0'+C[j+1:].replace('?','0'))
        Jmax =int('0'+J[j+1:].replace('?','9'))
        Jmin =int('0'+J[j+1:].replace('?','0'))
        [Cup ,Jup,same] = [10**len(Jbest)-Jmax+Cmin,10**len(Jbest)-Cmax+Jmin,mindif]            
        #print([Cup ,Jup,same])
        if (C[j]=='?') and (J[j]=='?'):
            if same<=min(Cup,Jup):
                Jbest ='0'+Jbest
                Cbest = '0'+Cbest
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
            if Cup<min(same,Jup):
                Jbest ='0'+J[j+1:].replace('?','9')
                Cbest = '1'+C[j+1:].replace('?','0')
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
            if Jup<=min(same,Cup):
                Jbest ='1'+J[j+1:].replace('?','0')
                Cbest = '0'+C[j+1:].replace('?','9')
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
        if (C[j]!='?') and (J[j]=='?'):
            if Jup <min(same,Cup) and C[j]<'9':
                Jbest = str(int(C[j])+1)+J[j+1:].replace('?','0')
                Cbest = C[j]+C[j+1:].replace('?','9')
            elif Cup <=same and C[j]>'0':
                Jbest = str(int(C[j])-1)+J[j+1:].replace('?','9')
                Cbest = C[j]+C[j+1:].replace('?','0')
            else:    
                Jbest = C[j]+Jbest
                Cbest = C[j]+Cbest 
            mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
            continue
        if (C[j]=='?') and (J[j]!='?'):
            if Cup <min(same,Jup) and J[j]<'9':
                Jbest = J[j]+J[j+1:].replace('?','9')
                Cbest = str(int(J[j])+1)+C[j+1:].replace('?','0')
            elif Jup <=same and J[j]>'0':
                Jbest = J[j]+J[j+1:].replace('?','9')
                Cbest = str(int(J[j])-1)+C[j+1:].replace('?','0')
            else:    
                Cbest = J[j]+Cbest
                Jbest=J[j]+Jbest
            mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
            continue
        if (C[j]!='?') and (J[j]!='?'):
            if C[j] ==J[j]:
                Cbest = C[j]+Cbest
                Jbest = J[j]+Jbest
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
            if C[j]>J[j]:
                Cbest=C[j:].replace('?','0')
                Jbest=J[j:].replace('?','9')
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
            if C[j]<J[j]:
                Cbest=C[j:].replace('?','9')
                Jbest=J[j:].replace('?','0')
                mindif  = abs(int('0'+Cbest)-int('0'+Jbest))
                continue
        #print(j)
    print("Case #"+str(Ca+1)+": "+Cbest+" "+Jbest+"\n")
    out.write("Case #"+str(Ca+1)+": "+Cbest+" "+Jbest+"\n")
f.close()
out.close()
