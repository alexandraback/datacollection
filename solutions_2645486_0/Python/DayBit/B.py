'''
Created on 27/04/2013

@author: David
'''
def read_data(filename):
    f=open(filename,'r')
    T=int(f.readline().strip())
    data = []
    for _ in range(T):
        E, R, N =(int(v) for v in f.readline().strip().split())
        values = [int(v) for v in f.readline().strip().split()]
        data.append((E,R,N,values))
    return data

def solve(e0,r,n0,v):
    def gain(n, e):
        if n==0: return 0
        if (n,e) not in mem:
            res = []
            for e2 in range(e+1):
                res.append(gain(n-1, min(e-e2+r,e0))+ e2*v[n-1])
            mem[(n,e)] = max(res)
        return mem[(n,e)]
    
    mem = {}
    return gain(n0, e0)
    
#data = read_data("B-test.in");
data = read_data("B-small-attempt0.in");

f2 = open("resB.txt", "w")
t = 1
for e,r,n,v in data:
    #print(e,r,n,v)
    sol=solve(e,r,n,v)
    cad = "Case #{0}: {1}".format(t,sol)
    print(cad)
    f2.write(cad+"\n")
    t += 1
f2.close()