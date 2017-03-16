def powerof2(a):
    while a%2==0:
        if a==2:
            return 1
        a=a/2
    return 0
test=input()
l=[]
for i in range(1,41):
    l.append(float(1.0/(2**i)));
for t in range(1,test+1):
    count=1
    s=raw_input()
    a,b=s.split("/")
    x= float(a)/float(b)
    if powerof2(int(b))==0:
        print "Case #"+str(t)+": impossible"
    else:
        j=0
        while x<l[j]:
            count+=1
            j+=1
        print "Case #"+str(t)+": "+str(count)
