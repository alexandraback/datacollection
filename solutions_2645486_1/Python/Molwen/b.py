import sys


def case(e,r,n,values):
    if r>=e:
        print(sum([x*e for x in values]))
        return
    c = e
    total = 0
    while len(values)>1:
        v = values.pop(0)
        if v>=max(values):
#            print(c,c)
            total += c*v
            c=0
        else:
            t = next(values.index(x) for x in values if x > v)+1
            if(c+(t*r))>e:
                s = min(c, c+(t*r)-e)
#                print(c,s,t)
                total += s*v
                c -= s
#            else:
#                print(c,0,t)
        c+=r
    total += c*values[0]
#    print(c,c)
        
        
        
    print(total) 
    return

def work(fin):
    t = int(fin.readline())
    for i in range(t):
        lawn = []
        print("Case #",i+1,": ",end="",sep="")
        temp = fin.readline().split()
        e,r,n = int(temp[0]),int(temp[1]),int(temp[2])
        values = list(map(int, fin.readline().strip().split()))
        case(e,r,n,values)

if __name__ == "__main__":
    INPUT = sys.argv[1]

    fin = open(INPUT,'r')
    work(fin)
