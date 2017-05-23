f1=open('C:/Python27/bazinga', 'w+')

linelist = []
for line in open('C:\Users\User\Downloads\C-small-attempt1.in'):
    linelist.append(line.rstrip('\n'));

testnum = int(linelist[0]);

for i in xrange(1,testnum+1):
    inlist = linelist[i].split()
    n = int(inlist[0])
    m=int(inlist[1])
    k=int(inlist[2])
    a = n-2
    b = m -2
    breakthrough = 0
    result = k
    if k<5:
        f1.write("Case #"+str(i)+": "+str(k)+"\n")
        continue
    for y in range(1,1+a):
        for z in range(1,1+b):
            if y*z +2*y+2*z >= k:
                if 2*y+2*z <= result:
                    result = 2*y+2*z
    f1.write("Case #"+str(i)+": "+str(result)+"\n")
    


f1.close()
