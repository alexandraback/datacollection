def check(t, s, v) :
    global p
    for x in v:
        tt = min(t,x)
        #print(x,tt)
        ss = p[x-1][tt-1]
        if ss > s:
            return False
        s -= ss
    return True

p = (
        (0,),
        (1,0),
        (2,1,0),
        (3,1,1,0),
        (4,2,1,1,0),
        (5,2,1,1,1,0),
        (6,3,2,1,1,1,0),
        (7,3,2,1,1,1,1,0),
        (8,4,2,2,1,1,1,1,0)
    )

T = int(input())
for t in range(1,T+1):
    d = int(input())
    v = list(map(int,input().split()))
    v.sort()
    v = v[::-1]
    kolko = v[0]
    #binarne vyhladat
    for i in range(1,v[0]):
        for j in range(1,i+1):
            sp = i-j
            if check(j,sp,v):
                kolko = i
                break
        if kolko < v[0]:
            break
    print("Case #%d: %d" % (t,kolko))
