#n=int(raw_input())
#a=[int(x) for x in raw_input().split()] 

filename='B-small-attempt0.in'
#filename='p.txt'
ff=open(filename)
newfile=open('output.txt','wb')

t=int(ff.readline())
a=0

while a<t:

    nums=ff.readline().split()
    c=float(nums[0])
    f=float(nums[1])
    x=float(nums[2])

    farms=0.0
    timeleft=0
    time=0
    timeleftifbuy=0
    ok=True
    while ok:
        timeleft=x/(2+farms*f)
        timeleftifbuy=(x)/(2+farms*f+f)+c/(2+farms*f)

        if timeleft<timeleftifbuy:
            ok=False
            time=time+timeleft
        else:
            time=time+c/(2+farms*f)
            farms=farms+1
        #print farms
    #print time
    answer=''
    answer='Case #'+str(1+a)+": "+str(time)
    newfile.write(answer)
    newfile.write('\r\n')

    a=a+1


newfile.close()
