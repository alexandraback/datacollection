'''
Created on 27/04/2013

@author: David
'''
def read_data(filename):
    f=open(filename,'r')
    T=int(f.readline().strip())
    data = []
    for _ in range(T):
        R,N,M,K=(int(v) for v in f.readline().strip().split())
        sets=[]
        for _ in range(R):
            sets.append([int(v) for v in f.readline().strip().split()])
        data.append((R,N,M,K, sets))
    return data

def solve(R,N,M,K,sets):
    f2 = open("resC.txt", "w")
    f2.write("Case #1:\n")
    print("Case #1:")
    for s in sets:
        res = []
        
        h3 = len([i for i in s if i%3==0])>0
        if (h3): res.append(3)
        
        h5 = len([i for i in s if i%5==0])>0
        if (h5): res.append(5)
        h2 = len([i for i in s if i%2==0])>0
        h4 = len([i for i in s if i%4==0])>0
        
        
        if (h2 and not h4): res.append(2)
        if (h4): res.append(4)
        if (h2 and h4 and len(res)<3): res.append(2)
        
        if len(res)==0:
            res=[2, 3, 4]
        while len(res)<3:
            res.append(res[0])
        #print(res)
        cad="".join([str(e) for e in res])
        f2.write(cad+"\n")
        print(cad)
    f2.close()

def gen(sd,ed,nd):
    pass

data = read_data("C-small-1-attempt0.in");

t = 1
for R,N,M,K, sets in data:
    #print(R,N,M,K,sets)
    solve(R,N,M,K,sets)
