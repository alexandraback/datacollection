# GS4444
# GCJ 2013 1C
# 6 May 2013

inner=open("B-small-attempt0.in",'r')
outter=open("out.txt",'w')
tc=int(inner.readline())
for z in range(1,tc+1):
    outter.write("Case #"+str(z)+": ")
    coord=list(map(int,inner.readline().split()))
    x=0
    y=0
    if coord[0]<coord[1]:
        if(coord[0]<0):
            while x!=coord[0]:
                x-=1
                outter.write('EW')
        elif(coord[0]>0):
            while x!=coord[0]:
                x+=1
                outter.write('WE')
        if(coord[1]<0):
            while y!=coord[1]:
                y-=1
                outter.write('NS')
        elif(coord[1]>0):
            while y!=coord[1]:
                y+=1
                outter.write('SN')
    else:
        if(coord[1]<0):
            while y!=coord[1]:
                y-=1
                outter.write('NS')
        elif(coord[1]>0):
            while y!=coord[1]:
                y+=1
                outter.write('SN')
        if(coord[0]<0):
            while x!=coord[0]:
                x-=1
                outter.write('EW')
        elif(coord[0]>0):
            while x!=coord[0]:
                x+=1
                outter.write('WE')
    outter.write('\n')
outter.close()
inner.close()
