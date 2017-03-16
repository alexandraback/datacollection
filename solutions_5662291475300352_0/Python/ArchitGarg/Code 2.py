import bisect
def ct(arr,x):
    count=0
    for i in range(0,len(arr)):
        if arr[i]<x:
            count+=1
        else:
            return count
    return count

lines=[]
file1=open('C-small-1-attempt0.in')
for line in file1:
    lines.append(line)
file1.close


T=int(lines[0])
ctr=1
f=open('Output.out','w')
cur=1
while ctr<=T:
    Arr=[]
    tempn=[int(x) for x in lines[cur].split()]
    N=tempn[0]
    cur+=1
    for i in range(0,N):
        Arr.append([int(x) for x in lines[cur+i].split()])
    cur+=N
    NewArr=[]
    for i in range(0,N):
        for j in range(0,Arr[i][1]):
            NewArr.append([Arr[i][0],Arr[i][2]+j])
    m=float('inf')
    T1=[]
    T2=[]
    T3=[]
    for i in range(0,len(NewArr)):
        T1.append((1-(NewArr[i][0]/360.0))*NewArr[i][1])
        T3.append([(1-(NewArr[i][0]/360.0))*NewArr[i][1],NewArr[i][1]])
        T2.append((2-(NewArr[i][0]/360.0))*NewArr[i][1])
    T1.sort()
    T2.sort()
    print T1
    print T2
    for i in range(0,len(T1)):
        count1=len(T1)-ct(T1,T1[i]+0.000001)
        count2=ct(T2,T1[i]+0.000001)
        if count1+count2<m:
            m=count1+count2
        
    
    f.write("Case #%d: %d" %(ctr,m))#print "Case #%d: YES" %(ctr)
    ctr+=1
    if ctr<=T:
        f.write("\n")
f.close()
