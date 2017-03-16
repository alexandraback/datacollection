T = int(input())

for t in range(T):
    #print('===============')
    N = int(input())

    L = list()
    
    for n in range(N):
        a, b = map(int, input().split())
        p = [a, b, 2]
        L.append(p)

    stars = 0
    moves = 0
    failed = False
    while L:
        #print('------------')
        #print("L:", L)
        #print('Stars:', stars)
        
        one_shoot = None
        for i in range(len(L)):
            p = L[i]
            if(p[1] <= stars):
                one_shoot = i
                break

        if one_shoot != None:
            #print("One-shooting level", L[one_shoot])
            stars += L[one_shoot][2]
            L.pop(one_shoot)
            moves += 1
            continue

        most_distant = None
        for i in range(len(L)):
            if (L[i][0] <= stars) and (L[i][2] == 2):
                if most_distant == None:
                    most_distant = i
                if  L[i][1] > L[most_distant][1]:
                    most_distant = i

        if most_distant != None:
            #print("Selecting pessimistic", L[most_distant])
            stars += 1
            p = L.pop(most_distant)
            if p[2] == 2:
                L.append( (p[0], p[1], 1) )
            moves += 1
            continue

        # none found...
        failed = True
        break
        
    if failed:
        print("Case #" + str(t+1) + ': Too Bad')
    else:
        print("Case #" + str(t+1) + ':', moves)
