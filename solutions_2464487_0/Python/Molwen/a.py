import sys


def case(r,t):
    k = 1
    used = 2*r*k + ((2*k)-1)*k
    while(used <= t):
        k*=2
        used = 2*r*k + ((2*k)-1)*k
    
    top = k
    bot = k/2
    while(top-bot > 1):
        k = (top+bot)/2
        used = 2*r*k + ((2*k)-1)*k
        if(used <= t):
            bot = k
        else:
            top = k
    used = 2*r*k + ((2*k)-1)*k
#   print(k, t, used)
    if(used <= t):
        print(int(k))
    else:
        print(int(k-1))
    return

def work(fin):
    n = int(fin.readline())
    for i in range(n):
        print("Case #",i+1,": ",end="",sep="")
        (r, t) = map(int,fin.readline().split())
        #print(r,t)
        case(r,t)

if __name__ == "__main__":
    INPUT = sys.argv[1]

    fin = open(INPUT,'r')
    work(fin)
