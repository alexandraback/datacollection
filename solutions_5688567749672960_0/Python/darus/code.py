#!/bin/python

def nines(K):
    num = ''
    for i in range(1, K+1):    
        num += '9'
    
    #print(K, num, "=>", int(num))

    return int(num)

def raise_to_power(K):
    #print("Raise to ", K)

    if (K == 1):
        return 0
    elif (K == 2):
        return 10
    else:
        K_2 = int((K - 1) / 2)
        return raise_to_power(K - 1) + nines(K_2) + nines((K - 1) - K_2) + 1;


def solve(N):

    if (N < 10):
        return N


    Ns = str(N)

    if (Ns[-1] == '0'):
        return solve(N - 1) + 1

    K = len(Ns)
    count = raise_to_power(K)

    count += int((Ns[::-1])[int((K+1)/2):])
    count += int(Ns[int(K/2):]) - 1

    if (int((Ns[::-1])[int((K+1)/2):]) > 1):
        count += 1
        
    #print(N, raise_to_power(K), int((Ns[::-1])[int((K+1)/2):]), (int(Ns[int(K/2):]) - 1))

    return count


T = int(input())

for i in range(0, T):
    N = int(input())
    print("Case #", (i+1), ": ", solve(N), sep='')
    

