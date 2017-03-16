def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
        
def power2(a):
    for i in range(0,41):
        if a==2**i:
            return True
    return False
    
def solve_for_one(p,q):
    x=gcd(p,q)
    p=p/x
    q=q/x
    if power2(q):
        for i in range(0,40):
            if 2*p>=q:
                return str(i+1)
            q=q/2
    return 'impossible'
        

def read_data():
    fin=open('input.txt','r')
    flines=fin.readlines()
    fin.close()
    T=int(flines[0])
    cases={}
    for i in range(1,T+1):
        line=flines[i].split('/')
        cases[i]=(int(line[0]),int(line[1]))
    return T,cases

def run_R1C_1():
    T,cases=read_data()
    fout=open('output.txt','w')
    for i in range(1,T+1):
        p,q = cases[i]
        answer=solve_for_one(p,q)
        fout.write('Case #'+str(i)+': '+answer+'\n')
    fout.close()
        
    
    
