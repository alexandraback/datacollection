import numpy as np

fin = open('cin.txt', 'r')
fout = open('cout.txt', 'w')

T = int(fin.readline())

def foo(a,b,c):
    x = [a+1,b+1,c+1]
    x = [str(i) for i in x]
    return " ".join(x)

def solve():
    J, P, S, K = tuple([int(i) for i in fin.readline().split()])

    poss = []
    for i in range(J):
        for j in range(P):
            for k in range(S):
                poss += [[i,j,k]]

    a = [[0 for x in range(P)] for y in range(J)]
    b = [[0 for x in range(S)] for y in range(J)]
    c = [[0 for x in range(S)] for y in range(P)]

    count = 0
    sol = ""

    for i,j,k in poss:
        if a[i][j] < K and b[i][k] < K and c[j][k] < K:
            count += 1
            sol += foo(i,j,k) + "\n"
            a[i][j] += 1
            b[i][k] += 1
            c[j][k] += 1

    return str(count) + "\n" + sol

    a = J * P * min(K, S)
    b = J * S * min(K, P)
    c = S * P * min(K, J)

    sol = ""

    if a == min(a,b,c):
        sol += str(a)+"\n"
        for i in range(J):
            for j in range(P):
                for k in range(min(K, S)):
                    sol += foo(i,j,k) + "\n"
    elif b == min(a,b,c):
        sol += str(b)+"\n"
        for i in range(J):
            for j in range(min(K, P)):
                for k in range(S):
                    sol += foo(i,j,k) + "\n"
    elif c == min(a,b,c):
        sol += str(a)+"\n"
        for i in range(min(K, J)):
            for j in range(P):
                for k in range(S):
                    sol += foo(i,j,k) + "\n"

    return sol

for i in range(T):
    fout.write("Case #" + str(i+1) + ": " + str(solve()))

fin.close()
fout.close()
