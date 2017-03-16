def dis(i):
    return list(map(int,str(i)))
    
def sleep(n):
    n=int(n)
    if n==0: return "INSOMNIA"
    d=set()
    for i in range(1,100):
        d.update(dis(n*i))
        if len(d)==10: return str(n*i)
    print(str(n)+" DID NOT RETURN")
    

inp=open("A-large.in")
inp.readline()
out=open("1la.txt","w")
case=1
for n in inp:
    out.write("Case #"+str(case)+": "+sleep(n[:-1])+"\n")
    case+=1
inp.close()
out.close()
    
