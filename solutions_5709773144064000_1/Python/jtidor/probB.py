import re
import math

inp=open("B-large.in","r")
outp=open("Bl_oupt.txt","w")
lines = inp.readlines()
inp.close()

def solve(c,f,x):
    if x<=c:
        return x/2.
    time=c/float(2)
    prod=float(2)
    while True:
        if x/(prod+f)+(c-x)/prod<0:
            prod+=f
            time+=c/prod
        else:
            time+=(x-c)/prod
            return time

k=int(lines.pop(0))

for i in range(k):
    a=re.sub("\n","",lines[i])
    a_inp=re.split(" ",a)
    outp.write("Case #"+str(i+1)+": "+str(solve(float(a_inp[0]),float(a_inp[1]),float(a_inp[2])))+"\n")
outp.close()
