#!/bin/python

def check(W, s, lengths):
    partials = list()

    count = 0

    for i in range(0, len(s)):
        a = s[i]
        for j in range(0, len(partials)):
            if (partials[j] >= 0):
                if (partials[j] >= len(W)):
                    count += 1
                    partials[j] = -1;
                elif W[partials[j]] == a:
                    partials[j] += 1
                else:
                    partials[j] = -1
        if W[0] == a:
            partials.append(1)

    for j in range(0, len(partials)):
        if (partials[j] >= len(W)):
            count += 1

    #print ('Check', s, count)

    if count in lengths:
        lengths[count] += 1
    else:
        lengths[count] = 1
    
def generate(S, A, W, lengths, s, i):
    if (i >= S):
        check(W, s, lengths)
        return

    for j in range(0, len(A)):
        generate(S, A, W, lengths, s + A[j], i + 1)
        

def solve(S, A, W):
    lengths = dict()
    
    generate(S, A, W, lengths, '', 0)

    avg = 0
    total = 0
    maxNum = 0

#    print (lengths)

    for num in lengths:
        avg += num * lengths[num]
        total += lengths[num]
        maxNum = max(maxNum, num)

    return maxNum - (avg / total)


T = int(input())

for i in range(0, T):
    K, L, S = [int(x) for x in input().split()]
    A = input()
    W = input()

    print("Case #", (i+1), ": ", solve(S, A, W), sep='')
    

