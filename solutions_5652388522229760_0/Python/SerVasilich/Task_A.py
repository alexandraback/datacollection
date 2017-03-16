fi=open("A-small-attempt1.in")
fo=open("A-smal.out","w")
def fnd(n):
    if n==0: return "INSOMNIA"
    s=set(str(n)); t,i=n,0
    while len(s)<10: 
        i+=1; t=n*i; s|=set(str(t))
    return t    
for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",fnd(int(fi.readline())),file=fo)
fi.close()
fo.close()
print("OK")