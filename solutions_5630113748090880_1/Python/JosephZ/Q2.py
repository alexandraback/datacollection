filename="B-large (1).in"
f1=open(filename)
number=int(f1.readline())
result_list=list()

for x in range(number):
    size=int(f1.readline())
    d=dict()
    for i in range(2*size-1):
        temp=f1.readline().strip().split(" ")
        for j in range(size):
            t=int(temp[j])
            if t in d.keys():
                d[t]+=1
            else:
                d[t]=1
    new_list=list()
    for y in d.keys():
        if d[y]%2!=0:
            new_list.append(y)
    result_list.append(sorted(new_list))
    
f2=open("output.txt",'w+')
for i in range(len(result_list)):
    line="Case #"+str(i+1)+": "
    for j in result_list[i]:
        line+=str(j)+" "
    line+="\n"
    f2.write(line)
f2.close()
            
