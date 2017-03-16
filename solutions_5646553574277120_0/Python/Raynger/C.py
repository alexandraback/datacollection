def can_make(value, coins):
    #print(coins)
    for i in coins:
        if i == value:
            return True
        else:
            new_coins = []
            for j in coins:
                new_coins.append(j)
            new_coins.remove(i)
            if can_make(value-i, new_coins):
                return True
    return False
            
                
        
for c in range(int(input())):
    C, D, V = list(map(int, input().split()))
    E = list(map(int, input().split()))
    counter = 0
    for i in range(1, V+1):
        if not(can_make(i, E)):
            #print(i)
            counter += 1
            E.append(i)
    print("Case #{}: {}".format(c+1, counter))    