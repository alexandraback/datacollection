import fractions
TXT=open('a.in')
inputlist=TXT.readlines()
TXT.close()

testCases=int(inputlist[0].strip())

line_cnt=1
OUT=open("a.out",'w')
for tc in xrange(1,testCases+1):
    lineList=inputlist [line_cnt ].strip().split('/')
    P=int (lineList[0])
    Q=int (lineList[1])
    line_cnt+=1
    gcd=fractions.gcd(P,Q)
    P=P/gcd
    Q=Q/gcd
##    print P
##    print Q
    if Q%2<>0:
        OUT.write(  "Case #%d: impossible\n" %(tc))
    else:
        two_multiple=Q
        flag=True
        while two_multiple>=2:
            if two_multiple%2<>0:
                flag=False
                break
            else:
                two_multiple/=2
        if flag:
            cnt=0
            while P<Q:
                P=P*2
                cnt+=1
            OUT.write(  "Case #%d: %d\n" %(tc,cnt))
        else:
            OUT.write(  "Case #%d: impossible\n" %(tc))
    #OUT.write(  "Case #%d: %d\n" %(tc,cnt))


OUT.close()

