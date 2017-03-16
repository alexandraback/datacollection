#!/bin/python

def try_buy(C, v, denoms, i):
    if v == 0: 
        return True

    if i >= len(denoms):
        return False

    for j in range(1, C + 1):
        if (v < denoms[i] * j):
            break

        if (v == denoms[i] * j):
            return True

        if try_buy(C, v - denoms[i] * j, denoms, i + 1):
            return True

    return try_buy(C, v, denoms, i+1)
        
def can_buy(C, v, denoms):
    return try_buy(C, v, denoms, 0)
    
def can_buy_all(C, V, denoms):
    for i in range(1, V + 1):
        if not can_buy(C, i, denoms):
#            print ('Failed to buy', V, 'with', denoms)
        
            return False

#    print ('OK to buy', V, 'with', denoms)
    return True

def try_denoms(C, V, D, denoms, max_sum, i, added):
    if i > int(V / 2) + 2:
        return 10000000000000

    if (max_sum >= V) and can_buy_all(C, V, denoms):
        return added

    while (i in D):
        i += 1

    r1 = try_denoms(C, V, D, denoms, max_sum, i + 1, added)

    denoms.append(i)
    r2 = try_denoms(C, V, D, denoms, max_sum + i * C, i + 1, added + 1)
    denoms.pop()

    return min(r1, r2)
    
def solve(C, V, D):
    denoms = list(D)
    
    max_sum = 0
    for d in denoms:
        max_sum += C * d

    return try_denoms(C, V, D, denoms, max_sum, 1, 0)


T = int(input())

for i in range(0, T):
   
    C, D, V = [int(x) for x in input().split()]

    initial = set([int(x) for x in input().split()])

    print("Case #", (i+1), ": ", solve(C, V, initial), sep='')
    

