import sys



readfromfile=1
if readfromfile==1:
    f = open('C:\\Users\\Tish\\Desktop\\EC Submisison (1)\D-large.in', 'r')
    g = open('C:\\Users\\Tish\\Desktop\\EC Submisison (1)\D-large.txt', 'w')
def read():
    if readfromfile==1:
        return f.readline()
    else:
        return input()
    
def finish(a):
    for i in range(10):
        if (a[i]==0):
            return 0
    return 1


def output(i,out):
    if readfromfile ==0:
        sys.stdout.write('Case #'+str(i+1)+': '+str(out)+'\n')
    else:
        g.write('Case #'+str(i+1)+': '+str(out)+'\n')

def my_print(x):
    if readfromfile ==0:
        sys.stdout.write(x)
    else:
        g.write(x)
        

def main1():
    t = int(read())
    for i in range(t):
        n=int(read())
        if n==0:
            output(i,'INSOMNIA')
        else:
            a=[0]*10
            j=1
            fin = 0
            while(fin==0):
                x=j*n
                while (x>0):
                    a[x%10]+=1
                    x=x//10
                fin=finish(a)
                j=j+1
            output(i,(j-1)*n)
    if readfromfile==1:
        g.close()


def q2():
    count = 0
    x=read()
    for i in range(len(x)-2):
        if (x[i+1]!=x[i]):
            count+=1
    if (x[len(x)-2]=='-'):
        count+=1
#    print(len(x))
#    print(x[0])
    return count

def printbin(r):
    while (r > 0 ):
        if (r%2 ==1):
            my_print('11')
        else:
            my_print('00')
        r=r//2
    for i in range(9):
        my_print(' '+str(i+3))
    my_print('\n')


def q3():
    t = int(read())
    x=int(read())
    j=int(read())
    if readfromfile ==0:
        sys.stdout.write('Case #1:\n')
    else:
        g.write('Case #1:\n')
    
    for i in range(j):
        r= 2**(x//2-1)+1+2*i
        printbin(r)
    if readfromfile==1:
        g.close()


def my_min(a,b):
    if a<b:
        return a
    return b
def con(i,c,k):
    res=0
    for j in range(c):
        res=res+ my_min(i*c +j,k-1)*(k**j)
    return res+1
def q4():
    inp = read()
    inpl= inp.split(' ')
    k = int(inpl[0])
    c = int(inpl[1])
    s = int(inpl[2])
    if (s*c) < k:
        return 'IMPOSSIBLE'
    res=[]
    for i in range((k+c-1)//c):
        res+=[con(i,c,k)]    
    return str(res).strip('[]').replace(',','')

def main():
    t = int(read())
    for i in range(t):
        output(i,q4())
    if readfromfile==1:
        g.close()

            
                
main()
