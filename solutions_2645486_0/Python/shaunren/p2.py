#!/usr/bin/python -SOO
maxe,r,n,vs = 0,0,0,[]
table = {}
def calc(k,e):
    global maxe,r,n,vs,table
    if (k,e) in table: return table[(k,e)]
    elif k==0: return max(vs[0]*min(maxe,maxe+r-e),0)
    else:
        table[(k,e)] = -1
        for i in range(max(0,e-r),maxe+1):
            x = calc(k-1,i)
            if x>=0: table[(k,e)] = max(table[(k,e)],x+min(i,i+r-e)*vs[k])
        return table[(k,e)]
for case in range(1,int(input())+1):
    maxe,r,n = map(int,input().strip().split())
    vs = list(map(int,input().strip().split()))
    table = {}
    #b = max(map(lambda x:calc(n-1,x),range(0,maxe+1)))
    b = calc(n-1,0)
    print('Case #{}: {}'.format(case,b))
