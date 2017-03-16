T = int(input())

for CC in range(T):
    C, D, V = map(int,input().split())
    Ds = list(map(int,input().split()))

    L = []

    for x in Ds:
        temp = L[:]
        for z in range(1,C+1):
            if x*z not in temp:
                temp.append(x*z)
        for y in L:
            for z in range(1,C+1):
                if x*z+y not in temp and x*z+y<=V:
                    temp.append(x*z+y)
        L = temp

    Ans = 0
    
    for x in range(1,V+1):
        if x in L:
            continue
        
        Ans += 1
        temp = L[:]
        for z in range(1,C+1):
            if x*z not in temp:
                temp.append(x*z)
        for y in L:
            for z in range(1,C+1):
                if x*z+y not in temp and x*z+y<=V:
                    temp.append(x*z+y)
        L = temp
        L.sort()
#        print(L)
        
    print('Case #{}: {}'.format(CC+1,Ans))
    
