t=input()
for case in range(0,t):
    nos=raw_input().split()
    c=float(nos[0])
    f=float(nos[1])
    x=float(nos[2])
    #print c,f,x,"zz"
    rate=float(2)
    curr_time=0
    while(True):
        t1=x/rate
        t2=c/rate+x/(f+rate)
        
        if(t1<t2):
            curr_time+=t1
            print "Case #%d: %.7f"%(case+1,curr_time)
            break
        else:
            curr_time+=c/rate
        rate=rate+f