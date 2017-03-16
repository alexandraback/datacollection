filename="C-small-attempt0 (1).in"
f1=open(filename)
number=int(f1.readline())
result_list=list()

def go_next(t,visited,fucked):
    next_one=edge[t]
    #print(visited)
    if next_one in fucked:
        return [0,visited+[next_one]]
    if (next_one in visited):
        if visited.index(next_one)==len(visited)-2:
            return [len(visited)-visited.index(next_one)+1, visited+[next_one]]
        return [len(visited)-visited.index(next_one) , visited+[next_one]]
    else:
        return go_next(next_one,visited+[next_one],fucked)

for x in range(number):
    edge=list()
    largest=0
    
    global largest
    n=int(f1.readline())
    line=f1.readline().strip().split(" ")
    for j in line:
        edge.append(int(j)-1)
    #start here
    for i in range(n):
        used2=[]
        temp=0
        j=i
        while len(used2)!=n:
            while j in used2:
                j+=1
            if j >= n:
                break
            h=go_next(j,[j],used2)
            t1,t2=h[0],h[1]
            temp=temp+t1
            used2=used2+t2
        if temp>largest:
            largest=temp
        
    result_list.append(largest)
    
    
f2=open("output.txt",'w+')
for i in range(len(result_list)):
    line="Case #"+str(i+1)+": "+str(result_list[i])+"\n"
    f2.write(line)
f2.close()
            
