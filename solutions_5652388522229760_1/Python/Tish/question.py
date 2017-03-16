import sys



readfromfile=0
if readfromfile==1:
    f = open('C:\\Users\\Tish\\Desktop\\EC Submisison (1)\A-large.in', 'r')
    g = open('C:\\Users\\Tish\\Desktop\\EC Submisison (1)\A-large.txt', 'w')
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
        

def main():
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
            
                
main()
