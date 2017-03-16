
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
fin = open('C-small-attempt1.in', 'r')
#fin = open('C-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):

    N = int(input())

    F = [int(x)-1 for x in input().split()]
    #print("F", F, file = sys.stderr)
    
    chain = [[] for x in range(N)]
    selfcontained = [0]*N
    ans = 0

    for i in range(N):
        chain[i] = [i]
        nextkid = i
        
        cont = 1
        while cont:
            bff = F[nextkid]
            if bff not in chain[i]:
                chain[i].append(bff)
                nextkid = bff
                continue
            elif bff == chain[i][-2]:
                ans = max(ans, len(chain[i]))
                selfcontained[i] = 1
                cont = 0
            elif bff == i:
                ans = max(ans, len(chain[i]))
                chain[i] = []
                cont = 0
            else:
                #i cannot sit
                chain[i] = []
                cont = 0

        #print("Chain i:", chain[i], ans, file = sys.stderr)
                
    
    #throw away competing chains
    for i in range(N):
        if chain[i] == []: continue
        for j in range(i+1,N):
            if chain[j] == []: continue
            if chain[i][-2:] != chain[j][-2:]:
                continue
            if len(chain[i]) >= len(chain[j]):
                chain[j] = []
            else:
                chain[i] = []
                break
        #print("who's left:", i, chain[i], ans, file = sys.stderr)
        
    sitters = set()
    for i in range(N):
        sitters = sitters.union(set(chain[i]))

    ans = max(ans,len(sitters))








    print("Case #%d:" % case, ans)
    print("Case #%d:" % case, ans, file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()