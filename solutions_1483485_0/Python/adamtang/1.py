import string
infile=open("d://1.txt")
outfile=open("d://2.txt","w")
lines=infile.readlines()
flag=False
counts=1

for line in lines:
    if flag==False:
        count=line
        flag=True
    else:
        result="Case #"+str(counts)+": "
        t=string.maketrans('abcdefghijklmnopqrstuvwxyz','yhesocvxduiglbkrztnwjpfmaq')
        result1=line.translate(t)
        result=result+result1
        counts=counts+1
        outfile.write(result)
infile.close()
outfile.close()
        
