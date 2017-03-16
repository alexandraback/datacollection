

T = input()

def reverse(num): 
    s = str(num)
    return int(s[::-1])


for t in range(1, T+1): 
    n = input()
    D = [0] * (n+1)

    for i in range(1, n+1): 
        if D[i] == 0: 
            D[i] = D[i-1] + 1
        else:
            D[i] = min(D[i], D[i-1] + 1)

        r = reverse(i)

        if r > i and r <= n:
            if D[r] == 0:
                D[r] = D[i] + 1
            else:
                D[r] = min(D[r], D[i] + 1)


    print 'Case #%d:' %(t), D[n]
