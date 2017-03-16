import numpy as np

fin = open('bin.txt', 'r')
fout = open('bout.txt', 'w')

T = int(fin.readline())

def solve():
    B, M = tuple([int(i) for i in fin.readline().split()])

    if M > 2**(B-2):
        return "IMPOSSIBLE\n"

    sol = "POSSIBLE\n"

    use = [0]*B

    if M == 2**(B-2):
        use = [1]*B
        use[-1] = 0
    else:
        i = 1
        m = M
        while m > 0:
            if m % 2 == 1:
                use[i] = 1
            i += 1
            m //= 2

    for i in range(B):
        s = ""
        for j in range(B-1):
            if j > i:
                s += "1"
            else:
                s += "0"
        s += str(use[i])
        sol += s + "\n"

    return sol

for i in range(T):
    fout.write("Case #" + str(i+1) + ": " + str(solve()))

fin.close()
fout.close()
