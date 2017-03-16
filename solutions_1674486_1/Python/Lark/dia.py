f = open("dia.large.in", "r")

import sys
sys.setrecursionlimit(2000)


T = int(f.readline())


N = []
M = []

for t in range(0, T):

    n = int(f.readline())

    N.append(n)
    M.append([])

    for j in range(0, n):
        M[t].append([])

        s = f.readline().split(" ")

        for o in range(0, int(s[0])):
            M[t][j].append(int(s[1+o]))
        

f.close()

def binary_search(arre, t, i, j):
    mid = ((j - i) / 2) + i
    t_mid = arre[mid]

    if t_mid == t:
        return True
    elif j <= i:
        return False
    elif t_mid > t:
        return binary_search(arre, t, i, mid - 1)
    elif t_mid < t:
        return binary_search(arre, t, mid + 1, j)

def hurkanga(i, m, save):
    neig = m[i-1]

    for ne in neig:
        if not (ne in save):
            save += [ne]
            hurkanga(ne, m, save)
        

f = open("dia.out", "w")

for t in range(0, T):

    n = N[t]
    m = M[t]

    print str(t)
    
    kanga = {}

    for i in range(1, n+1):
        D = [i]
        hurkanga(i, m, D)
        kanga[i] = sorted(list(D))

    print "hur"

    dia = False

    # i = utgangs nod
    for i in range(1, n+1):
        neig = m[i-1]

        for p in range(1, n+1):

            #if (p == i):
            #    break

            po = 0
            for ne in neig:
                #if p in kanga[ne]:
                #    po += 1

                if binary_search(kanga[ne], p, 0, len(kanga[ne])-1):
                    po += 1

            if po > 1:
                dia = True
                break

        if (dia):
            break

    if dia:
        f.write("Case #" + str(t + 1) + ": Yes\n")
    else:
        f.write("Case #" + str(t + 1) + ": No\n")
                
        
f.close()

print "done"




















