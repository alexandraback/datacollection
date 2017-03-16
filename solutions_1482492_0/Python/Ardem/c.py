fin=open('in.txt','r')
fout=open('out.txt','w')

d=int(fin.readline())    

for l in range(d):
    n,m=map(int,fin.readline().split())
    ta=map(int,fin.readline().split())
    a=[]
    for i in range(len(ta)/2):
        a.append([ta[2*i],ta[2*i+1]])
    b=[]
    tb=map(int,fin.readline().split())
    for i in range(len(tb)/2):
        b.append([tb[2*i],tb[2*i+1]])
    

    
