fin=open("/home/cbeauseigne/Desktop/in.txt","r")
fout=open("/home/cbeauseigne/Desktop/out.txt","w")
s=fin.read().split("\n")
print(s)

z=int(s[0])

print(z)

for k in range(z):
    zz=s[k+1].split(" ")
    r=int(zz[0])
    c=int(zz[1])
    w=int(zz[2])
    x=r*(c//w)
    x+=w
    if c%w==0:x-=1
    fout.write("Case #"+str(k+1)+": "+str(x)+"\n")
    