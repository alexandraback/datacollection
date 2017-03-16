# python3
def solve():
    N=int(input())
    mis=set()
    for i in range(2*N-1):
        li=input()
        for new in li.split():
            nnew=int(new)
            if nnew in mis:
                mis.remove(nnew)
            else:
                mis.add(nnew)
    miss=list(mis)
    miss.sort()
    return ' '.join(str(e) for e in miss)
 
T=int(input());
 
for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())
