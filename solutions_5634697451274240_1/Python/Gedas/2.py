import re

def sleep(n):
    return len(re.findall('\-+',n))*2-(n[0]=='-') #yay ducktyping

inp=open("B-large.in")
inp.readline() #trusting all the lines in input are important
out=open("2la.txt","w")
case=1
for n in inp:
    out.write("Case #"+str(case)+": "+str(sleep(n[:-1]))+"\n")
    case+=1
inp.close()
out.close()
    
