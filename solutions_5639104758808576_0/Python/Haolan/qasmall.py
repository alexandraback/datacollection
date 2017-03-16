N = int(raw_input())
for i in range(N):
    n, b = raw_input().split()
    n = int(n)
    ls = [int(b[j]) for j in range(n + 1)]

    sum = 0
    invitation = 0
    for j in range(n + 1):
        if ls[j] == 0:
            continue
        if sum >= j:
            sum += ls[j]
        else:
            invitation += j - sum
            sum += ls[j] + invitation
    print 'Case #'+str(i+1)+': '+str(invitation)
