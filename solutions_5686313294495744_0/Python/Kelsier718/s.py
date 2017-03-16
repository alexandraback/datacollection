import numpy as np

def perm(l):
    count = 0
    for j in range(len(l[0])):
        if j > l[0].index(l[0][j]) and j > l[1].index(l[1][j]):
            count = count + 1
    return count

t = int(input())
for i in range(1, t + 1):
    n = int(input())
    l = [[0 for j in range(n)], [0 for j in range(n)]]
    for j in range(n):
        l[0][j],l[1][j] = input().split(' ')
    m = 0
    for k in range(10**4):
        p = np.random.permutation(n)
        newL = [[l[0][j] for j in p],[l[1][j] for j in p]]
        m = max(m,perm(newL))
    print("Case #{}: {}".format(i, m))
