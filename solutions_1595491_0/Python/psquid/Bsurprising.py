f = open("in",'r')

T = int(input())

for t in range(T):
    l = [int(x) for x in input().split()]
    N,S,p = l[0],l[1],l[2]
    
    ans, doable, sdoable = 0,0,0
    for m in l[3:]:
        if p > 1 and m >= 3*p-4 and m < 3*p-2:
            sdoable += 1
        if m >= 3*p-2:
            doable += 1
    ans = doable + min(S,sdoable)
    if p == 0: ans = N
    
    print("Case #"+str(t+1)+": "+str(ans))
