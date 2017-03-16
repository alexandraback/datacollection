import sys



f = open('C:\\Users\\Tish\\Desktop\\input5.in', 'r')
g = open('C:\\Users\\Tish\\Desktop\\output.txt', 'w')
def read():
        return f.readline()
    
def finish(a):
    for i in range(10):
        if (a[i]==0):
            return 0
    return 1


def output(i,out):
    g.write('Case #'+str(i+1)+': '+str(out)+'\n')

def my_print(x):
    g.write(x)



def q1():
    n=int(read())
    a=read().strip().split(' ')
    for i in range(n):
        a[i]=int(a[i])

    m=0
    m2=0
    ind=-1
    ind2=-1
    for i in range(n):
        if (m<a[i]):
            m=a[i]
            ind=i
    for i in range(n):
        if i != ind:
            if (m2<a[i]):
                m2=a[i]
                ind2=i
    res=""
    for i in range(m-m2):
        res=res+ chr(ord('A')+ind)+" "
    for i in range(n):
        if i != ind and i != ind2:
            for j in range(a[i]):
                res=res+chr(ord('A')+i)+" "
    for i in range(m2-1):
        res=res+chr(ord('A')+ind)+chr(ord('A')+ind2)+" "
    res=res+chr(ord('A')+ind)+chr(ord('A')+ind2)
    return res

def q2(test):
    a=read().strip().split(' ')
    b=int(a[0])
    m=int(a[1])
    if m>(2**(b-2)):
        g.write('Case #'+str(test+1)+': '+ 'IMPOSSIBLE'+'\n')
        return
    g.write('Case #'+str(test+1)+': '+ 'POSSIBLE'+'\n')
    x=0
    for i in range(b):
        if (2**x)<m:
            x= x+1
    mat=[[0 for i in range(b)] for j in range(b)] 
    for i in range(x+1):
        for j in range(i):
            mat[j][i]=1
    if (2**x) == m:
        for i in range(x+1):
            mat[i][x+1]=1
    else:
        s=1
        while m>0:
            if m %2 ==1:
                mat[s][x+1]=1
            m=m//2
            s=s+1
    for i in range (b-x-2):
        mat[x+1+i][x+2+i]=1
    for i in range(b):
        for j in range(b):
            my_print(str(mat[i][j]))
        my_print('\n')

def main():
    t = int(read())
    for i in range(t):
        q2(i)
    g.close()

            
                
main()
