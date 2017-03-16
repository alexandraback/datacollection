import math
f=open("B-small-attempt0.in","r")
f2=open("output.txt","w")
n=int(f.readline())
for i in range(0,n):
    lst=[]
    cor=f.readline()
    cor_list=cor.split(" ")
    x=int(cor_list[0])
    y=int(cor_list[1])
    print x
    if x>0:
        for j in range(0,int(math.fabs(x))):
          lst.append("W")
          lst.append("E")
    if x<0:
        for j in range(0,int(math.fabs(x))):
          lst.append("E")
          lst.append("W")

    if y>0:
        for j in range(0,int(math.fabs(y))):
          lst.append("S")
          lst.append("N")
    if y<0:
        for j in range(0,int(math.fabs(y))):
          lst.append("N")
          lst.append("S")

    strr="".join(lst)
    s="Case #"+str(i+1)+":"+" "+strr+"\n"
    f2.write(s)
f.close()
f2.close()
