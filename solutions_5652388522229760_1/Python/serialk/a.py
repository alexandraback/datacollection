#!/usr/bin/python3

def answer(n):
    if n == 0:
        return 'INSOMNIA'
    k = 0
    need_to_see = set(range(0, 10))
    while need_to_see:
        k += n
        for i in str(k):
            i = int(i)
            if i in need_to_see:
                need_to_see.remove(i)
    return k


T = int(input())
for i in range(T):
    N = int(input())
    print('Case #{}: {}'.format(i + 1, answer(N)))
