f=open("C-small-attempt0.in","r")
lists=f.readlines()
tests=int(lists[0])
i=1
while i<=tests:
    values=lists[i].split(' ')        
    intval=[int(each) for each in values]
    a=intval[0]
    b=intval[1]
    length=len(str(b))
    val1=a
    val2=b
    total=0
    mul=10**(length-1)
    if a==b or (b<10):
        total=0
    else:
        while val1<val2:
            tempcnt=0
            temp=val1
            k=0
            test=[]
            while k<length:                
                temp=(temp/10) + ((temp%10)*mul)
                if temp!=val1 and a<=temp and temp<=b:
                    if temp<val1:
                        tempcnt=0
                        break
                    elif temp not in test:
                        test.append(temp)
                        tempcnt+=1
                k=k+1
            if tempcnt!=0:
                tempcnt=tempcnt+1
                total=total+(((tempcnt)*(tempcnt-1))/2)
            val1=val1+1
    print "Case #%d: %d" %(i,total)
    i=i+1
