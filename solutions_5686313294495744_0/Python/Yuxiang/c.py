t = int(input())

for z in range(t):
    n = int(input())
    pool = []
    for i in range(n):
        pool.append(tuple(raw_input().split(' ')))
    
    fake_pool = [False for i in range(n)]
    
    real_dict = ({}, {})
    real_dict[0][pool[0][0]] = [0]
    real_dict[1][pool[0][1]] = [0]
    
    
    for i in range(1, n):
        # print real_dict
        first = pool[i][0]
        second = pool[i][1]
        if first in real_dict[0] and second in real_dict[1]:
            fake_pool[i] = True
            continue
        if first in real_dict[0]:
            potential = real_dict[0][first][:]
            for p in potential:
                s = pool[p][1]
                if len(real_dict[1][s]) > 1:
                    fake_pool[p] = True
                    real_dict[1][s].remove(p)
                    real_dict[0][first].remove(p)
            real_dict[0][first].append(i)
            real_dict[1][second] = [i]
            continue
        if second in real_dict[1]:
            potential = real_dict[1][second][:]
            for p in potential:
                f = pool[p][0]
                if len(real_dict[0][f]) > 1:
                    fake_pool[p] = True
                    real_dict[0][f].remove(p)
                    real_dict[1][second].remove(p)
            real_dict[0][first] = [i]
            real_dict[1][second].append(i)
            continue
        real_dict[0][first] = [i]
        real_dict[1][second] = [i]
        
        
    count = 0
    for f in fake_pool:
        if f:
            count += 1
    print "Case #{}: {}".format(z + 1, count)
    

