#!/usr/bin/env python3
T = int(input())

# M[0] don't matter
M = ['lol', 1]

for t in range(T):
    N = int(input())

    if N >= len(M):
        for i in range(len(M), N+1):
            if i % 10 == 0:
                M.append(M[-1] + 1)
            else:
                rev = int(str(i)[::-1])
                if rev < i:
                    M.append(min(M[rev], M[-1]) + 1)
                else:
                    M.append(M[-1] + 1)
    nums = M[N]
    
    print('Case #{}: {}'.format(t+1, nums))
