def rush(l,total,current_star,tt):
    d=[]
    a=l[:]
    if len(l)==0:
        if tt*2!=current_star:
            print "error!!"
        return total
    if [l[0]]==l:
        if current_star>=l[0][1]:
            a.remove(l[0])
            total=total+1
            if l[0][0]==-1:
                current_star+=1
            else:
                current_star+=2
            return rush(a,total,current_star,tt)
    else:
        for i in range(len(l[:])):
            if current_star>=l[i][1] and l[i][0]!=-1:
                a.remove(l[i])
                total=total+1
                if l[i][0]==-1:
                    current_star+=1
                else:
                    current_star+=2
                return rush(a,total,current_star,tt)                
        for i in range(len(l[:])):
            if current_star>=l[i][1]:
                a.remove(l[i])
                total=total+1
                if l[i][0]==-1:
                    current_star+=1
                else:
                    current_star+=2
                return rush(a,total,current_star,tt)
    if [l[0]]==l:
        if current_star>=l[0][0] and l[0][0]>=0:
            a[0][0]=-1
            total+=1
            current_star+=1
            return rush(a,total,current_star,tt)
    else:
        mi=-1
        large_value=-1
        for i in range(len(l[:])):
            if current_star>=l[i][0] and l[i][1]>large_value and l[i][0]!=-1:
                large_value=l[i][1]
                mi=i
        if mi>=0:
            a[mi][0]=-1
            total+=1
            current_star+=1
            return rush(a,total,current_star,tt)
        #for i in range(len(l[:])):
            #if current_star>=l[i][0] and l[i][0]>=0:
                #a[i][0]=-1
                #total+=1
                #current_star+=1
                #return rush(a,total,current_star,tt)
    return "Too Bad"
    
    
def test():
    filename="B-small-attempt7.in"
    filea=open(filename,'r')
    fileb=open('out-put','w')
    total=int(filea.readline().strip())
    for case in range(1,total+1):
        ss='Case #'+str(case)+": "
        number=int(filea.readline().strip())
        l=[]
        for i in range(number):
            li=str(filea.readline().strip()).split(" ")
            l.append([int(li[0]),int(li[1])])
        print l
        ss=ss+str(rush(l,0,0,len(l)))
        fileb.write(ss+'\n')
        
    