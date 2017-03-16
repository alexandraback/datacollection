import sys
from math import sqrt
from collections import defaultdict

def case(prods):
    facs = list(map(factors,prods))
#    print("facs =", facs)
    lst=[]
    threes_list = [d[3] for d in facs]
#    print("threes_list =", threes_list)
    fives_list = [d[5] for d in facs]
#    print("fives_list =", fives_list)
    fours_list = [d[4] for d in facs]
#    print("fours_list =", fours_list)
    if len(threes_list)>0:
        threes = max(threes_list)
        lst += ([3]*threes)
    if len(fives_list)>0:
        fives = max(fives_list)
        lst += ([5]*fives)
    if len(fours_list)>0:
        fours = max(fours_list)
        lst += ([4]*fours)
    twos_list = [d[2] for d in facs] 
#    print("twos_list =", twos_list)
    if 1 in twos_list:
        lst += [2]
    elif 3 in twos_list:
        lst += [2]
    l = len(lst)
#    print(lst)
    if l == 3:
        for i in lst:
            print(i,sep="",end="")
        print("")
        return
    if len(twos_list) > 0 and max(twos_list)>1:
        lst += [4]
    lst += ([2]*(3-l))
#    print(lst)
    l = len(lst)
    if l == 3:
        for i in lst:
            print(i,sep="",end="")
        print("")
    if l > 3:
        for i in range(l-3):
            lst.pop()
        for i in lst:
            print(i,sep="",end="")
        print("")
    return
    
    

def factors(num):
    d = defaultdict(int)
    facs = []
    while(num>1):
        for i in range (2,m+1):
            if num%i==0:
                num/=i
                facs.append(i)
                break
    if(len(facs)>3):
        facs=[4]+facs[2:] 
    for i in facs:
        d[i]+=1
    return d

def work(fin):
    t = int(fin.readline())
    for i in range(t):
        lawn = []
        print("Case #",i+1,": ",sep="")
        temp = fin.readline().split()
        global r
        global n
        global m
        global k
        r,n,m,k = int(temp[0]),int(temp[1]),int(temp[2]),int(temp[3])
        for i in range(r):
            prods = list(map(int,fin.readline().split()))
            case(prods)

if __name__ == "__main__":
    INPUT = sys.argv[1]

    fin = open(INPUT,'r')
    work(fin)
