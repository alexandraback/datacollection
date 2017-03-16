def jinzhi(s,n):
    res=0
    for i in range(len(s)):
        res+=int(s[-(i+1)])*n**i
    return res

def zhengchu(n):
    for i in range(2,n):
        if n%i==0:
            return i
    return(-1)
        
def checkmagic(NN):
    s=NN+" "
    for i in range(2,11):
        N=jinzhi(NN,i)
        s+=(str(zhengchu(N)))+" "
    return s

def xuaner(n):
    lst=[]
    for i in range(n):
        for j in range(n-i-1):
            s="0"*i+"1"+"0"*j+"1"+"0"*(n-i-j-2)
            lst.append(s)
    return lst

def heti(s1,s2):
    s=""
    for i in range(len(s1)):
        s+=s1[i]+s2[i]
    return(s)



file=open("C-large.in")
line=file.readline()
line=file.readline()
w=line.split()
n=int(w[0])
k=int(w[1])
m=(n-2)//2
lst1=xuaner(m)
lst=[]
for i in lst1:
    for j in lst1:
        if len(lst)>=k:
            break
        s="1"+heti(i,j)+"1"
        lst.append(s)


outfile=open("output.txt","w")
outfile.write("Case #1:\n")
for i in lst:
    outfile.write(checkmagic(i)+"\n")

outfile.close()

