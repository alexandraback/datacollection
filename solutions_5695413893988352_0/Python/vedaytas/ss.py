t=input()

a3=[]
for tt in range(1,t+1):
    a1=[]
    a2=[]
    print "Case #%d: " %(tt),
    s1,s2=raw_input().split()
    f=0
    for i in range (0,len(s1)):
       if s1[i]=='?':
           f=1
           break

    if f==0:
        a1.append(s1)

    f=0
    for i in range (0,len(s2)):
       if s2[i]=='?':
           f=1
           break

    if f==0:
        a2.append(s2)
    for i in range(0,len(s1)):
        if s1[i]=='?':
            for j in range(0,10):
                s=s1[0:i]+str(j)+s1[i+1:]
                a1.append(s)
            break
    for i in range(0,len(s2)):
        if s2[i]=='?':
            for j in range(0,10):
                s=s2[0:i]+str(j)+s2[i+1:]
                a2.append(s)
            break
    a3=[]
    f=0
    for z in range(0,len(a1)):
        s1=a1[z]
        for i in range(0,len(s1)):
            if s1[i]=='?':
                f=1
                for j in range(0,10):
                    s=s1[0:i]+str(j)+s1[i+1:]
                    a3.append(s)
                break
    if f==1:
        a1=a3
    f=0
    a3=[]
    #for i in range(0,len(a1)):
        #print a1[i]
    for z in range(0,len(a1)):
        s1=a1[z]
        for i in range(0,len(s1)):
            if s1[i]=='?':
                f=1
                for j in range(0,10):
                    s=s1[0:i]+str(j)+s1[i+1:]
                    a3.append(s)
                break
    if f==1:
        a1=a3
    f=0
    a3=[]
    for z in range(0,len(a2)):
        s1=a2[z]
        for i in range(0,len(s1)):
            if s1[i]=='?':
                f=1
                for j in range(0,10):
                    s=s1[0:i]+str(j)+s1[i+1:]
                    a3.append(s)
                break
    if f==1:
        a2=a3
    f=0
    a3=[]
    for z in range(0,len(a2)):
        s1=a2[z]
        for i in range(0,len(s1)):
            if s1[i]=='?':
                f=1
                for j in range(0,10):
                    s=s1[0:i]+str(j)+s1[i+1:]
                    a3.append(s)
                break
    if f==1:
        a2=a3
    mi=10000
    sz=""
    sy=""
    for i in range(0,len(a1)):
        for j in range(0,len(a2)):
            x=int(a1[i])
            y=int(a2[j])
            #print x,y
            if  abs(y-x)<mi:
                sy=a1[i]
                sz=a2[j]
                mi=abs(y-x)
    print sy,sz
    
                
    
        
