#!/usr/bin/env pypy3

T = input()
N, J = map(int, input().split())

def checkbase(cand, b):
    cnd = int(bin(cand)[2:], b)
    for i in [2, b+1]:
        if cnd % i == 0:
            return i

def comb(n, k):
    if n == 0:
        if k == 0:
            yield 0
    else:
        for c in comb(n-1, k):
            yield c
        if k != 0:
            for c in comb(n-1, k-1):
                yield (1<<(n-1)) + c

count = 0

print("Case #1:")
for cnt in range(0, N-2, 2):
    if count == J:
        break
    for c in comb((N-2)//2, cnt//2):
        if count == J:
            break
        l = ['0'] * (N-2)
        l[0:N-2:2] = bin(c)[2:].rjust(N//2-1, '0')
        for d in comb((N-2)//2, cnt//2):
            if count == J:
                break
            l[1:N-2:2] = bin(d)[2:].rjust(N//2-1, '0')
            cand = 2*int(''.join(l), 2) + 1 + (1<<(N-1))
            divs = []
            for b in range(2, 11):
                tmp = checkbase(cand, b)
                if tmp is not None:
                    divs.append(tmp)
                else:
                    break
            if len(divs) == 9:
                count+=1
                print(bin(cand)[2:], " ".join(str(i) for i in divs))
