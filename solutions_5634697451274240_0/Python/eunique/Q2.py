z=open("B-small-attempt0.in","r")
outputfile=open("outputfile.txt","w")
a = z.readline()
for b in range(0,int(a)):
    c=z.readline()
    differs=0
    for d in range(0,len(c)-2):
        if c[d]!=c[d+1]:
            differs+=1
    if c[-2]=="-":
        differs+=1
    outputfile.write("Case #"+str(b+1)+": "+str(differs)+ "\n")

z.close()
outputfile.close()
