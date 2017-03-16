#

##a=n/3
##
##1)n%3==0
##
##normal : a
##weird : a+1
##
##2)n%3==1
##
##normal : a+1
##weird : np
##
##3)n%3==2
##
##normal : a+1
##weird : a+2

f=open('a6','r')
f2=open('out','w')

num=int(f.readline().strip())

for i in range(0,num):
    narray=[int(n) for n in f.readline().strip().split(' ')]
    nog=narray[0]
    wc=narray[1]
    bscore=narray[2]
    narray=narray[3:]
    ctr=0
    wctr=0
    for score in narray:
        a=score/3
        b=score%3
        if score==0:
            if bscore==0:
                ctr+=1
        elif score==1:
            if score>=bscore:
                ctr+=1
        elif score==2:
            if bscore==1 or bscore==0:
                ctr+=1
            elif bscore==2:
                wctr+=1
        elif b==0:
            if (a)>=bscore:
                ctr+=1
            elif (a+1)>=bscore:
                wctr+=1
        elif b==1:
            if (a+1)>=bscore:
                ctr+=1
        elif b==2:
            if (a+1)>=bscore:
                ctr+=1
            elif (a+2)>=bscore:
                wctr+=1
    ctr=ctr+min(wctr,wc)
    print ctr
    f2.write("Case #%d: %d\n" % (i+1,ctr))

f2.close()
