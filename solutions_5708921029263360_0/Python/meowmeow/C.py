def check(comb,K):
    #print comb,K
    f13 = {}
    f23 = {}
    f12 = {}
    for a,b,c in comb:
        f12[(a,b)] = f12.get((a,b),0) + 1
        f13[(a,c)] = f13.get((a,c),0) + 1
        f23[(b,c)] = f23.get((b,c),0) + 1
        if f12[(a,b)] > K or f13[(a,c)] > K or f23[(b,c)] > K:
            return False
    return True



from itertools import product
from itertools import combinations

F = open('C-small-attempt0.in')
O = open('C-small-attempt0.out','w')

#F = open('A-large-practice.in')
#O = open('A-large-practice.out','w')

a3331 = ((1, 1, 1), (1, 2, 2), (1, 3, 3), (2, 1, 2), (2, 2, 3), (2, 3, 1), (3, 1, 3), (3, 2, 1), (3, 3, 2))
a3332 = ((1, 1, 1), (1, 1, 2), (1, 2, 1), (1, 2, 3), (1, 3, 2), (1, 3, 3), (2, 1, 1), (2, 1, 3), (2, 2, 2), (2, 2, 3), (2, 3, 1), (2, 3, 2), (3, 1, 2), (3, 1, 3), (3, 2, 1), (3, 2, 2), (3, 3, 1), (3, 3, 3))
a3333 = ((1, 1, 1), (1, 1, 2), (1, 1, 3), (1, 2, 1), (1, 2, 2), (1, 2, 3), (1, 3, 1), (1, 3, 2), (1, 3, 3), (2, 1, 1), (2, 1, 2), (2, 1, 3), (2, 2, 1), (2, 2, 2), (2, 2, 3), (2, 3, 1), (2, 3, 2), (2, 3, 3), (3, 1, 1), (3, 1, 2), (3, 1, 3), (3, 2, 1), (3, 2, 2), (3, 2, 3), (3, 3, 1), (3, 3, 2), (3, 3, 3))

T = int(F.readline())

print T

for case in range(1,T+1):
    J,P,S,K = map(int,F.readline().rstrip().split())
    if J == P == S == 3:
        if K == 1:
            O.write("Case #%d: %d\n"%(case,9))
            for i in a3331:
                O.write("%d %d %d\n"%(i[0],i[1],i[2]))
                

        elif K == 2:
            O.write("Case #%d: %d\n"%(case,18))
            for i in a3332:
                O.write("%d %d %d\n"%(i[0],i[1],i[2]))

        else:
            O.write("Case #%d: %d\n"%(case,27))
            for i in a3333:
                O.write("%d %d %d\n"%(i[0],i[1],i[2]))
        continue
            


    total = []
    for i in range(1,J+1):
        for j in range(1,P+1):
            for k in range(1,S+1):
                total.append((i,j,k))
                
    #for i in total:
    #    print i

    ans = 0
    rec = None
    
    for t in range(1,J*P*S+1):
        x = combinations(total,t)
        for comb in x:
            #print comb
            if check(comb,K) is True:
                ans = t
                rec = comb
                break
        else:
            break


    print ans,rec
    
    O.write("Case #%d: %d\n"%(case,ans))
    for i in rec:
        O.write("%d %d %d\n"%(i[0],i[1],i[2]))

    
F.close()
O.close()
