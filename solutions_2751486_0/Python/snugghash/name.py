# GS4444
# GCJ 2013 1C
# 6 May 2013

inner=open("A-small-attempt2.in",'r')
outter=open("out.txt",'w')
tc=int(inner.readline())
for z in range(1,tc+1):
    one=inner.readline().split()
    name=one[0]
    n=int(one[1])
    value=0
    x=0
    prevind=0
    #print(str(len(name)))
    for index,letter in enumerate(name):
        #print(str(index))
        if letter=='a' or letter=='e' or letter=='i' or letter=='o' or letter=='u':
            continue
        else:
            flag=0
            for i in range(index+1,index+n):
                #print(str(i)+' '+str(z))
                if i>len(name)-1:
                    flag=1
                    break
                if name[i]=='a' or name[i]=='e' or name[i]=='i' or name[i]=='o' or name[i]=='u':
                    #print('vowel;')
                    flag=1
                    break
            #print('flag'+str(flag))
            if flag==0:
                #print(str(z)+'hoo')
                value+=len(name)-n+1-x
                x+=1
                if index+n==len(name) or index==0:
                    hoop=0
                else:
                    value-=len(name)-n+1-(x-1)                    
                    print('hoola'+str(z))
                    for d in range(1,index+1):
                        value+=len(name)-index-n+1
            prevind=index
            index+=n
    outter.write("Case #"+str(z)+": "+str(value)+'\n')
outter.close()
inner.close()
