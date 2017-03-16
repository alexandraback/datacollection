import sys
sys.setrecursionlimit(1000000000)

T = int(input())
for N in range(1, T + 1):
    out = 'Case #' + str(N) + ': '
    n = int(input())
    bff = [int(i) - 1 for i in input().split()]
    
    prec = [[] for _ in range(n)]
    for i in range(n):
        prec[bff[i]].append(i)
        
    poids = [0 for _ in range(n)]
    still = [True for _ in range(n)]
    modi = True
    
    modif = True
    while modif:
        modif = False
        for i in range(n):
            if still[i] and prec[i] == []:
                modi = False
                modif = True
                still[i] = False
                poids[bff[i]] = max(poids[bff[i]], poids[i] + 1)
                prec[bff[i]].remove(i)
    
                
    add = 0
    bestp = 0
    for i in range(n):
        if still[i]:
            j = i
            to_add = 0
            bb = 0
            while still[j]:
                still[j] = False
                bb += 1
                to_add += poids[j]
                j = bff[j]
            if bb == 2:
                add += to_add + 2
            bestp = max(bestp, bb)
    out += str(max(add, bestp))
    out += '\n'
    sys.stdout.write(out)
    sys.stdout.flush()
    sys.stderr.write(out)
    sys.stderr.flush()